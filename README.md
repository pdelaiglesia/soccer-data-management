# Football Data Management en C++

Este proyecto implementa un sistema completo en C++ para gestionar información futbolística a partir de archivos CSV.  
Permite cargar datos de clubes, jugadores y alineaciones, y ofrece un menú interactivo para realizar consultas avanzadas.

## Funcionalidades principales

### 1. Carga masiva de datos
El sistema importa información desde tres archivos CSV:
- `clubs.csv`
- `players.csv`
- `game_lineups.csv`

Durante la carga:
- Se procesan millones de registros.
- Se convierten cadenas en valores numéricos y fechas.
- Se crean objetos de las clases `Club`, `Player` y `gameLineup`.

### 2. Menú principal de clubes
El usuario puede:
- Buscar un club por nombre o comienzo del nombre.
- Ver jugadores del club, alineaciones y mejor jugador.
- Ordenar jugadores.
- Consultar la edad media del club.

### 3. Menú general de clubes
Incluye opciones como:
- Mostrar clubes por liga.
- Ordenar clubes por:
  - Edad media
  - Tamaño de plantilla

### 4. Sistema de búsqueda de clubes
- Búsqueda por coincidencia inicial de cadena.
- Presentación de resultados y selección interactiva.
- Acceso al menú específico del club seleccionado.

### 5. Procesamiento de datos
El programa:
- Identifica ligas únicas.
- Recorre vectores dinámicos de forma eficiente.
- Convierte fechas en formato `YYYY-MM-DD`.
- Verifica y corrige campos vacíos en los CSV.

## Archivos requeridos

El programa espera tres archivos CSV en el mismo directorio:


