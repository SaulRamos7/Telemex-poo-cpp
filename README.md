# Telemex - Sistema de Gestión Administrativa (POO)

Este es mi proyecto final de la materia de Seminario de Programación, es un sistema de consola desarrollado en C++ que simula la gestión operativa y administrativa de una empresa proveedora de servicios de telecomunicaciones (Telemex). Este proyecto fue diseñado para aplicar y demostrar los fundamentos de la Programación Orientada a Objetos (POO).

## Características Principales

El sistema orquesta cuatro módulos principales a través de un menú interactivo:

*   **Módulo de Empleados:** Sistema CRUD completo para el registro del personal, incluyendo validaciones de entrada para números de empleado, códigos, RFC y fechas de ingreso
*   **Módulo de Sucursales:** Gestión de las distintas sedes de la empresa, almacenando datos clave como domicilio, ciudad, estado y nombre del gerente a cargo
*   **Catálogo de Servicios:** Despliegue de políticas de servicio y paquetes de telecomunicaciones (desde Cable Básico hasta paquetes Triple Play con Internet y Telefonía), integrando tabuladores de costos y porcentajes de comisión para empleados.
*   **Módulo de Contratos:** Administración de los folios de servicio contratados por los clientes mediante un sistema de alta, baja y modificación de registros

## Tecnologías y Conceptos Aplicados
*   **Lenguaje:** C++
*   **Arquitectura:** Programación Orientada a Objetos (POO)
*   **Conceptos Destacados:** 
    *   Encapsulamiento y separación de lógica (Archivos `.h` y `.cpp`).
    *   Manejo de variables y métodos estáticos para control de memoria y conteo global de instancias
    *   Validación robusta de tipos de datos en la entrada del usuario (`cin.fail()`, limpieza de buffer).
    *   Manipulación de arreglos de objetos.

## Cómo ejecutar el proyecto

1. Clona este repositorio en tu máquina local.
2. Asegúrate de tener un compilador de C++ instalado (como MinGW o GCC).
3. Compila el proyecto enlazando todos los archivos fuente:
   ```bash
   g++ src/main.cpp src/Empleado.cpp src/Sucursal.cpp src/Servicio.cpp src/Contrato.cpp -o telemex_app