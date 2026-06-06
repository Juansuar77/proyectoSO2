KMonitor - Módulo Cargable del Kernel Linux (LKM)
Descripción

KMonitor es un Módulo Cargable del Kernel (Loadable Kernel Module - LKM) desarrollado en lenguaje C para Linux. Su propósito es recopilar métricas básicas del sistema directamente desde estructuras internas del kernel y exponer esta información al espacio de usuario mediante una entrada en el sistema de archivos virtual /proc.

El módulo permite visualizar información sobre el uso de memoria del sistema y el listado de procesos activos, incluyendo su identificador, nombre y estado actual.

Objetivos del Proyecto
Comprender el funcionamiento interno del Kernel Linux.
Manipular estructuras de datos del kernel de forma segura.
Implementar módulos cargables del kernel (LKM).
Utilizar la interfaz /proc para exponer información al usuario.
Obtener métricas de memoria desde estructuras internas del sistema.
Recorrer la tabla de procesos utilizando mecanismos propios del kernel.
Funcionalidades Implementadas
Creación de Entrada en /proc

Al cargar el módulo mediante insmod, se crea automáticamente el archivo:

/proc/kmonitor_grupo1
Monitoreo de Memoria

El módulo obtiene y muestra:

Memoria total del sistema.
Memoria libre disponible.
Porcentaje de utilización de memoria.

Ejemplo:

Memoria total: 4008388 KB
Memoria libre: 407040 KB
Uso: 89%
Monitoreo de Procesos

El módulo recorre la lista de procesos activos del sistema y muestra:

PID (Process ID)
Nombre del proceso
Estado del proceso

Ejemplo:

PID      Nombre                    Estado
1        systemd                   Sleeping
2        kthreadd                  Sleeping
3        pool_workqueue_           Sleeping
...
Eliminación Segura

Al descargar el módulo mediante rmmod, la entrada creada en /proc es eliminada automáticamente.

Permite obtener información sobre la memoria del sistema.

Utilizada mediante:

struct sysinfo si;
si_meminfo(&si);

Datos obtenidos:

totalram
freeram
mem_unit
struct task_struct

Es la estructura principal que representa un proceso dentro del kernel Linux.

Se utiliza para acceder a:

task->pid
task->comm
task->__state
for_each_process()

Macro del kernel que permite recorrer todos los procesos activos.

Uso:

for_each_process(task)
{
    ...
}

Esta macro simplifica la navegación sobre la lista global de procesos administrada por el kernel.

proc_create()

Función encargada de registrar una nueva entrada dentro del sistema de archivos virtual /proc.

Uso:

proc_create(PROC_NAME, 0, NULL, &proc_file_ops);
remove_proc_entry()

Elimina la entrada creada en /proc cuando el módulo es descargado.

Uso:

remove_proc_entry(PROC_NAME, NULL);
Archivos del Proyecto
kmonitor.c

Archivo principal del módulo.

Contiene:

Inicialización del módulo.
Liberación del módulo.
Obtención de métricas de memoria.
Recorrido de procesos.
Implementación de la interfaz /proc.
Makefile

Archivo encargado de automatizar la compilación del módulo utilizando el sistema de construcción del kernel Linux.

Permite ejecutar:

make

para compilar el módulo y:

make clean

para limpiar archivos generados.

README.txt

Documento descriptivo del proyecto y guía básica de uso.

Compilación

Ubicarse en la carpeta del proyecto:

cd kmonitor

Compilar:

make
Carga del Módulo
sudo insmod kmonitor.ko

Verificar que fue cargado:

lsmod | grep kmonitor
Lectura de Información
cat /proc/kmonitor_grupo1
Descarga del Módulo
sudo rmmod kmonitor

Verificar eliminación:

ls /proc | grep kmonitor

Si no aparece salida, el módulo fue descargado correctamente.

Resultados Obtenidos

El módulo logró:

Crear correctamente una entrada en /proc.
Obtener métricas reales de memoria desde el kernel.
Recorrer y mostrar la lista de procesos activos.
Traducir estados internos del kernel a estados comprensibles para el usuario.
Eliminar correctamente los recursos utilizados al descargarse.
Tecnologías Utilizadas
Lenguaje C
Linux Kernel Modules (LKM)
Ubuntu Linux
VirtualBox
Sistema de archivos virtual /proc
GCC
Make

Autores

JHOSELYN NAYELHY LÓPEZ RAMOS
JOSSELINE MARIA PORTILLO RAMIREZ
JUAN JOSÉ SUAR PANJOJJUAN JOSÉ SUAR PANJOJ
