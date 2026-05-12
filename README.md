Módulos Cargables del Kernel y Sistema de Archivos /proc
Proyecto desarrollado para el curso de Sistemas Operativos II utilizando módulos cargables del kernel (Loadable Kernel Modules - LKM) en Linux.

Descripción
Este proyecto consiste en la creación de un módulo básico del kernel en Linux tipo Hello World, capaz de:


Cargarse dinámicamente en el kernel


Crear un archivo dentro del sistema virtual /proc


Mostrar texto estático desde espacio de usuario


Registrar mensajes en el kernel usando printk


El objetivo principal fue comprender el funcionamiento básico de los módulos del kernel y la interacción con el sistema de archivos /proc.

Tecnologías utilizadas


Lenguaje C


Linux Kernel Modules (LKM)


Ubuntu Linux


GCC


Makefile


Sistema /proc



Estructura del proyecto
tarea1_modulo/│├── hello_proc.c├── Makefile└── README.md

Conceptos utilizados
🔹 Loadable Kernel Module (LKM)
Los módulos cargables permiten extender funcionalidades del kernel sin reiniciar el sistema operativo.
🔹 Sistema /proc
/proc es un sistema de archivos virtual utilizado para interactuar con información del kernel y procesos activos.
🔹 Macros del kernel utilizadas


MODULE_LICENSE


MODULE_AUTHOR


module_init()


module_exit()



🚀 Compilación
Compilar el módulo:
make
Esto generará:
hello_proc.ko

📥 Cargar el módulo
sudo insmod hello_proc.ko

📌 Verificar módulo cargado
lsmod | grep hello_proc

📂 Verificar archivo /proc
ls /proc | grep hello_kernel

📖 Leer contenido del archivo /proc
cat /proc/hello_kernel
Salida esperada:
Hello World

🧾 Ver mensajes del kernel
sudo dmesg | tail
Ejemplo:
Hello World: modulo cargado

🗑️ Descargar módulo
sudo rmmod hello_proc

✅ Resultado esperado
Después de remover el módulo:
ls /proc | grep hello_kernel
No debe mostrar resultados, indicando que el archivo fue eliminado correctamente.

📸 Evidencia experimental
El proyecto incluye pruebas funcionales utilizando:


make


insmod


lsmod


rmmod


dmesg


lectura de /proc



👨‍💻 Autor
Juan Suar
Ingeniería en Sistemas
Universidad Mariano Gálvez de Guatemala

📄 Licencia
Proyecto educativo desarrollado con fines académicos.
