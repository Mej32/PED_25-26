#!/usr/bin/env python3
"""
Ejecutor de TADs - Ejecuta todos los tests agrupados por tipo
"""

import subprocess
import os
import glob
import re
import time
import sys
from collections import defaultdict

# Colores ANSI
class Color:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    RED = '\033[91m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    END = '\033[0m'

# Mapeo de prefijos a nombres de TAD
TAD_NOMBRES = {
    'C': 'Complejo',
    'V': 'Vector',
    'L': 'Lista',
    'P': 'Pila',
    'A': 'ABB',
    # Agregar mas tipos segun sea necesario
}

def obtener_tipo_tad(nombre_ejecutable):
    """Extrae el tipo de TAD del nombre del ejecutable (ej: tadC01 -> C)"""
    match = re.search(r'tad([A-Z])\d+', nombre_ejecutable)
    if match:
        return match.group(1)
    return None

def ejecutar_tad(ruta_ejecutable):
    """Ejecuta un TAD y devuelve el resultado"""
    try:
        resultado = subprocess.run(
            [ruta_ejecutable],
            capture_output=True,
            text=True,
            timeout=10
        )
        return {
            'exito': resultado.returncode == 0,
            'stdout': resultado.stdout,
            'stderr': resultado.stderr,
            'codigo': resultado.returncode
        }
    except subprocess.TimeoutExpired:
        return {
            'exito': False,
            'stdout': '',
            'stderr': 'TIMEOUT: El test tardo mas de 10 segundos',
            'codigo': -1
        }
    except Exception as e:
        return {
            'exito': False,
            'stdout': '',
            'stderr': str(e),
            'codigo': -1
        }

def mostrar_separador(char='=', longitud=60):
    print(char * longitud)

def main():
    # Obtener directorio del script
    directorio = os.path.dirname(os.path.abspath(__file__))

    # Buscar todos los ejecutables tad*
    patron = os.path.join(directorio, 'tad*')
    ejecutables = sorted([f for f in glob.glob(patron) if os.path.isfile(f) and os.access(f, os.X_OK)])

    if not ejecutables:
        print(f"{Color.RED}No se encontraron ejecutables TAD en {directorio}{Color.END}")
        return

    # Agrupar por tipo
    tads_por_tipo = defaultdict(list)
    for exe in ejecutables:
        nombre = os.path.basename(exe)
        tipo = obtener_tipo_tad(nombre)
        if tipo:
            tads_por_tipo[tipo].append(exe)

    # Estadisticas globales
    total_tests = 0
    total_exitos = 0

    print()
    print(f"{Color.BOLD}{Color.HEADER}")
    mostrar_separador('=')
    print("          EJECUTOR DE TADs - Resultados")
    mostrar_separador('=')
    print(f"{Color.END}")

    # Ejecutar por tipo
    for tipo in sorted(tads_por_tipo.keys()):
        nombre_tad = TAD_NOMBRES.get(tipo, f'Tipo {tipo}')
        ejecutables_tipo = tads_por_tipo[tipo]

        print(f"\n{Color.BOLD}{Color.CYAN}")
        mostrar_separador('-')
        print(f"  {nombre_tad.upper()} ({len(ejecutables_tipo)} tests)")
        mostrar_separador('-')
        print(f"{Color.END}")

        exitos_tipo = 0

        for exe in ejecutables_tipo:
            nombre = os.path.basename(exe)
            total_tests += 1

            # Mostrar que se esta ejecutando
            print(f"  {Color.BOLD}{nombre}{Color.END} ... ", end='')
            sys.stdout.flush()

            resultado = ejecutar_tad(exe)

            if resultado['exito']:
                print(f"{Color.GREEN}[OK]{Color.END}")
                exitos_tipo += 1
                total_exitos += 1
            else:
                print(f"{Color.RED}[FALLO]{Color.END}")
                # Solo mostrar salida si falla
                if resultado['stdout'].strip():
                    for linea in resultado['stdout'].strip().split('\n'):
                        print(f"    {linea}")

                if resultado['stderr'].strip():
                    print(f"    {Color.RED}Error: {resultado['stderr'].strip()}{Color.END}")

                if resultado['codigo'] != 0:
                    print(f"    {Color.YELLOW}Codigo de salida: {resultado['codigo']}{Color.END}")

            time.sleep(0.5)

        # Resumen del tipo
        color_resumen = Color.GREEN if exitos_tipo == len(ejecutables_tipo) else Color.YELLOW
        print(f"\n  {color_resumen}Resultado {nombre_tad}: {exitos_tipo}/{len(ejecutables_tipo)} tests pasados{Color.END}")

    # Resumen global
    print(f"\n{Color.BOLD}{Color.HEADER}")
    mostrar_separador('=')
    print("                RESUMEN GLOBAL")
    mostrar_separador('=')
    print(f"{Color.END}")

    porcentaje = (total_exitos / total_tests * 100) if total_tests > 0 else 0

    if total_exitos == total_tests:
        color_final = Color.GREEN
        mensaje = "TODOS LOS TESTS PASARON"
    elif total_exitos > total_tests / 2:
        color_final = Color.YELLOW
        mensaje = "ALGUNOS TESTS FALLARON"
    else:
        color_final = Color.RED
        mensaje = "MUCHOS TESTS FALLARON"

    print(f"\n  {color_final}{Color.BOLD}{mensaje}{Color.END}")
    print(f"  Tests pasados: {Color.BOLD}{total_exitos}/{total_tests}{Color.END} ({porcentaje:.1f}%)")

    # Barra de progreso visual
    ancho_barra = 40
    lleno = int(ancho_barra * porcentaje / 100)
    barra = '█' * lleno + '░' * (ancho_barra - lleno)
    print(f"  [{color_final}{barra}{Color.END}]")

    print()
    mostrar_separador('=')
    print()

if __name__ == '__main__':
    main()
