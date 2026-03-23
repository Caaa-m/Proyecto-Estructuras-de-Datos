# Proyecto-Estructuras-de-Datos

**CURSO:** Estructura de Datos y Algoritmos - S2661-1270  
**DOCENTE:** Carlos Alvarez Henao  
**ESTUDIANTES:** Maria Camila Rodriguez Gonzalez - Pablo Alvarez Restrepo  

---

## Descripción

Programa en C++ que ordena un dataset de 100,000 palabras usando tres estrategias algorítmicas distintas, con análisis comparativo de rendimiento en tiempo y memoria.

---

## Estructura del Proyecto

```
PROYECTO-ESTRUCTURAS-DE-DATOS/
├── main.cpp                         # Programa principal con menú interactivo
├── dataset.txt                      # Dataset de palabras
├── Bases/
│   └── Estructuras.h                # Implementación de Pila y Cola con nodos
├── Funciones_Palabras/
│   ├── Crear_txt.h / .cpp           # Generador de palabras aleatorias
│   ├── Convertir_txt.h / .cpp       # Carga dataset.txt a vector<string>
│   └── Randomizar.h / .cpp          # Desordena el dataset aleatoriamente
├── Ordenamiento/
│   ├── Quick_Sort.h / .cpp          # QuickSort sobre std::vector
│   ├── Heap_Sort.h / .cpp           # HeapSort con Binary Heap
│   └── AVL_Tree.h / .cpp            # AVL Tree con inorder traversal
└── Recursos/
    ├── Tiempo.h / .cpp              # Medición de tiempo con std::chrono
    └── Memoria.h / .cpp             # Estimación de memoria con sizeof
```

---

## Cómo ejecutar

1. Asegurarse de tener `dataset.txt` en la raíz del proyecto
2. Compilar todos los archivos `.cpp` junto con `main.cpp`
3. Ejecutar el programa con:

```
.\programa.exe
```

4. Seguir el menú interactivo:

```
SELECCIONAR DATASET
1. Usar dataset existente     → usa dataset.txt del profesor (lo randomiza antes)
2. Generar dataset aleatorio  → genera palabras inventadas y las guarda en dataset.txt

MENU
1. Ver dataset        → muestra las palabras (originales u ordenadas)
2. Ordenar dataset    → elige entre QuickSort, HeapSort o AVL
3. Ver estadísticas   → muestra tiempo y memoria del último ordenamiento
4. Ver complejidad    → muestra el Big-O del algoritmo usado
0. Salir
```

---

## Enfoque de Implementación

### QuickSort
Se implementó usando el esquema de Lomuto con el último elemento como pivote. El arreglo se particiona en cada llamada recursiva y se ordenan los subarreglos izquierdo y derecho por separado. Las palabras se almacenan en un `std::vector<string>` y se comparan alfabéticamente con el operador `<`.

### HeapSort
Se implementó construyendo un max-heap sobre el mismo `std::vector<string>`. El proceso tiene dos fases: primero se construye el heap llamando a `heapify` desde el centro hacia la raíz en O(n), luego se extrae el elemento mayor (raíz) y se restaura el heap repetidamente hasta ordenar todo el arreglo.

### AVL Tree
Se implementó un árbol AVL completo con rotaciones simples (izquierda y derecha) y dobles (izquierda-derecha y derecha-izquierda). Cada nodo almacena su altura para calcular el balance. Las palabras se insertan una a una y el árbol se balancea automáticamente. El ordenamiento final se obtiene con un recorrido inorder que retorna las palabras en orden alfabético.

### Randomizar
Usa `srand(time(0))` como semilla y mezcla el vector con intercambios aleatorios (`rand() % size`), sobreescribiendo el mismo `dataset.txt`.

### Estructuras base
Se implementaron una **Pila** y una **Cola** usando nodos enlazados (`struct Nodo`) con las operaciones básicas: `push/pop/top` para la pila y `enqueue/dequeue/front` para la cola.

---

## Complejidad Algorítmica (Big-O)

| Algoritmo  | Mejor caso  | Caso promedio | Peor caso   | Memoria adicional |
|------------|-------------|---------------|-------------|-------------------|
| QuickSort  | O(n log n)  | O(n log n)    | O(n²)       | O(log n)          |
| HeapSort   | O(n log n)  | O(n log n)    | O(n log n)  | O(1)              |
| AVL Tree   | O(n log n)  | O(n log n)    | O(n log n)  | O(n)              |

---

## Mediciones de Rendimiento

| Algoritmo  | Tiempo (s)  | Memoria aprox (KB) |
|------------|-------------|--------------------|
| QuickSort  |150 - 300 ms | 4,000-6,000 KB     |
| HeapSort   |400 - 700 ms | 4,000-6,000 KB     |
| AVL Tree   |800 - 1500 ms| 6,000 - 10,000 KB  |

---

## Análisis Comparativo

*QuickSort y HeapSort trabajan sobre el mismo std::vector<string>, por eso su memoria es similar. Con 100,000 palabras de promedio 7 caracteres, el vector ocupa alrededor de 4-5 MB.*

*AVL Tree consume más porque crea un nodo (new AVLNode) por cada palabra, y cada nodo tiene: el string, dos punteros y un int de altura.*

*QuickSort es el más rápido porque accede a memoria de forma contigua (mejor uso de caché).*

*HeapSort es más lento que QuickSort a pesar del mismo Big-O por los saltos aleatorios en memoria.*

*AVL Tree es el más lento por el overhead de las rotaciones y las 100,000 llamadas a new.*



### ¿Por qué la complejidad teórica a veces difiere de los resultados prácticos?

Aunque QuickSort y HeapSort tienen el mismo Big-O promedio O(n log n), en la práctica QuickSort suele ser más rápido. Esto se debe a su mejor comportamiento con la caché del procesador: accede a posiciones de memoria contiguas, mientras que HeapSort salta entre posiciones distantes del arreglo. El AVL Tree es más lento en la práctica por el overhead de las rotaciones y el uso de memoria dinámica (una `new` por cada nodo insertado).

### Ventajas y desventajas de cada estructura

**QuickSort (vector)**

*Ventajas:*
- Muy rápido en la práctica por buena localidad de caché
- In-place, bajo consumo de memoria adicional O(log n) por la pila de recursión

*Desventajas:*
- Peor caso O(n²) si el pivote siempre es el mayor o menor elemento

**HeapSort (Binary Heap)**

*Ventajas:*
- Garantiza O(n log n) en todos los casos sin excepción
- In-place, memoria adicional O(1)

*Desventajas:*
- Más lento que QuickSort en la práctica por peor localidad de caché

**AVL Tree**

*Ventajas:*
- Garantiza O(log n) por inserción con balance automático
- Útil si además de ordenar se necesitan búsquedas e inserciones frecuentes

*Desventajas:*
- Mayor consumo de memoria por los nodos dinámicos: O(n) nodos en el heap
- Overhead de rotaciones en cada inserción desbalanceada

---

## Conclusiones

A partir de las mediciones obtenidas con el dataset de 100,000 palabras, se puede concluir que **QuickSort fue el algoritmo más eficiente en la práctica**, con tiempos entre 150 y 300 ms, a pesar de que en teoría comparte el mismo Big-O promedio O(n log n) con los otros dos algoritmos. Esto confirma que la complejidad teórica no siempre refleja el rendimiento real: QuickSort se beneficia de la localidad de caché al acceder a posiciones contiguas del vector, lo que lo hace significativamente más rápido en hardware moderno.
 
**HeapSort** mostró tiempos entre 400 y 700 ms. Aunque garantiza O(n log n) incluso en el peor caso (ventaja sobre QuickSort), sus accesos no contiguos a memoria lo hacen más lento en la práctica. Es la mejor opción cuando se necesita una garantía estricta de tiempo sin importar el orden de los datos.
 
**AVL Tree** fue el más lento, con tiempos entre 800 y 1500 ms, y el mayor consumo de memoria (6,000 - 10,000 KB) debido a las 100,000 llamadas a `new` para crear nodos y el overhead de las rotaciones de balanceo. Sin embargo, su valor real no está en el ordenamiento puro sino en que permite búsquedas e inserciones en O(log n) después de construido, lo que lo hace ideal para aplicaciones donde los datos cambian constantemente.
 
En conclusión, para el problema específico de ordenar un dataset estático de palabras, **QuickSort es la opción más apropiada** por su velocidad práctica y bajo consumo de memoria. HeapSort es preferible cuando se requiere estabilidad en el peor caso, y el AVL Tree cuando la estructura de datos necesita soportar operaciones dinámicas más allá del ordenamiento inicial.