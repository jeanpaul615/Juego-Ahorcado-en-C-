
# Juego del Ahorcado en C++ 🎮

Este repositorio contiene una implementación del clásico **Juego del Ahorcado** desarrollado en **C++**. Es una excelente manera de divertirse mientras se practica programación estructurada y lógica.

---

## 🌟 **Descripción del Proyecto**

El **Juego del Ahorcado** consiste en adivinar una palabra oculta intentando letra por letra. Cada error acerca al jugador a ser "ahorcado". Este proyecto está diseñado para ser jugado en la terminal y pone en práctica conceptos básicos de programación como estructuras de control, manejo de cadenas y entrada/salida.

---

## ✨ **Características**

- **Interfaz de consola**: Juego basado en texto con instrucciones claras y fáciles de seguir.
- **Selección de palabras aleatorias**: Cada partida es única, con palabras seleccionadas de una lista predefinida.
- **Control de errores**: Lleva un registro de letras acertadas y errores cometidos.
- **Progresión visual**: Representación del progreso del "ahorcado" en cada intento fallido.
- **Código modular**: Fácil de entender y extender.

---

## 🚀 **Cómo Empezar**

Sigue los pasos a continuación para clonar y ejecutar el proyecto en tu máquina local:

1. **Clona este repositorio**:
   ```bash
   git clone https://github.com/jeanpaul615/Juego-Ahorcado-en-C-.git
   ```

2. **Accede al directorio del proyecto**:
   ```bash
   cd Juego-Ahorcado-en-C-
   ```

3. **Compila el código fuente**:
   ```bash
   g++ -std=c++11 main.cpp -o ahorcado
   ```

4. **Ejecuta el juego**:
   ```bash
   ./ahorcado
   ```

---

## 📋 **Reglas del Juego**

1. El programa selecciona una palabra aleatoria.
2. Intenta adivinar la palabra introduciendo una letra por turno.
3. Cada letra correcta se revela en la palabra oculta.
4. Cada letra incorrecta añade una parte al dibujo del "ahorcado".
5. Ganas si completas la palabra antes de que el dibujo del "ahorcado" se complete.

---

## 🛠️ **Requisitos**

- **Compilador C++**: g++, clang, o equivalente.
- **C++11** o superior.

---

## 📂 **Estructura del Proyecto**

- **main.cpp**: Contiene la lógica principal del juego.
- **palabras.txt** *(opcional)*: Archivo con una lista de palabras para el juego (si implementado).
- **README.md**: Documentación del proyecto.

---

## 🎨 **Capturas de Pantalla**

> *(Opcional: Incluye imágenes o capturas de pantalla que muestren el juego en funcionamiento.)*

---

## 🤝 **Contribuciones**

¡Las contribuciones son bienvenidas! Si encuentras errores, tienes ideas para nuevas funcionalidades o mejoras, sigue estos pasos:

1. Haz un fork del repositorio.
2. Crea una nueva rama para tus cambios:
   ```bash
   git checkout -b feature/nueva-funcionalidad
   ```
3. Realiza tus cambios y haz un commit:
   ```bash
   git commit -m "Agrega nueva funcionalidad"
   ```
4. Envía los cambios a tu repositorio:
   ```bash
   git push origin feature/nueva-funcionalidad
   ```
5. Abre un [pull request](https://github.com/jeanpaul615/Juego-Ahorcado-en-C-/pulls).

---
