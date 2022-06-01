/*
6) Crear una estructura que permita cargar los siguientes registros: cedula, nombre y apellido,
curso, parcial 1, parcial 2, trabajo practico, donde se debe prestar atención a los siguientes
detalles:
- Los datos ingresados deben ser validados, es decir, en campos numéricos no deben
ser permitidos datos alfanuméricos y viceversa.
- Las parciales deben tener valores en los rangos de 0 a 15 puntos.
- El trabajo practico debe tener un rango de 0 a 10 puntos.
- La calificación dependerá del total de puntos el cual es la sumatoria entre las parciales
y el trabajo practico. A su vez, la calificación deberá ser calculado teniendo en cuenta
la siguiente escala.
Calificación Desde Hasta
1 0 27
2 28 30
3 31 34
4 35 37
5 38 40
A partir de los datos ingresados, mostrar los siguientes resultados
- Opción 1: Mostrar los datos ingresados en forma de tabla
- Opción 2: Ingresar un curso y filtrar la lista por el curso ingresado
- Opción 3: Ingresar la cedula de identidad de un alumno, y filtrar los datos del mismo
- Opción 4: Salir del Programa 
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct registro
{
    int cedula;
    string nombre;
    string carrera;
    int parc_1;
    int parc_2;
    int tp;
};

void cantIng(int &);

bool errorCarga(void);

bool tieneNum(string);

int calificacion(int, int, int);

void selectorOpcion(int &);

main()
{
    int n, opcion, cantEncontrados = 0, cedula;
    string curso;
    system("cls");
    cout << "Programa para cargar registro de estudiantes.\n";
    cantIng(n);
    struct registro persona[n];
    //Carga de Datos a la Estructura
    for (int i = 0; i < n; i++)
    {
        system("cls");
        cout << "================================================"
             << "\n";
        cout << "Carga de Datos. Persona " << i + 1 << "\n";
        do
        {
            cout << "Numero de Cedula: ";
            cin >> persona[i].cedula;
        } while (persona[i].cedula <= 0 || errorCarga());
        cout << "\n";
        do
        {
            cout << "Nombre y Apellido: ";
            cin >> persona[i].nombre;
        } while (tieneNum(persona[i].nombre) || errorCarga());
        cout << "\n";
        do
        {
            cout << "Carrera: ";
            cin >> persona[i].carrera;
        } while (tieneNum(persona[i].carrera) || errorCarga());
        cout << "\n";
        do
        {
            cout << "Parcial 1: ";
            cin >> persona[i].parc_1;
        } while (persona[i].parc_1 < 0 || persona[i].parc_1 > 15 || errorCarga());
        cout << "\n";
        do
        {
            cout << "Parcial 2: ";
            cin >> persona[i].parc_2;
        } while (persona[i].parc_2 < 0 || persona[i].parc_2 > 15 || errorCarga());
        cout << "\n";
        do
        {
            cout << "Trabajo Practico: ";
            cin >> persona[i].tp;
        } while (persona[i].tp < 0 || persona[i].tp > 10 || errorCarga());
        cout << "================================================"
             << "\n";
    }
    do
    {
        system("cls");
        selectorOpcion(opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            cout << "Opcion seleccionada: " << opcion << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << "Alumno: " << i + 1 << "\n";
                cout << "Numero de Cedula: " << persona[i].cedula << "\n";
                cout << "Nombre: " << persona[i].nombre << "\n";
                cout << "Puntaje del Parcial 1: " << persona[i].parc_1 << "\n";
                cout << "Puntaje del Parcial 2: " << persona[i].parc_2 << "\n";
                cout << "Puntaje de Trabajo Practico: " << persona[i].tp << "\n";
                cout << "====================================================="
                     << "\n";
            }
            break;
        case 2:
            cout << "Opcion seleccionada: " << opcion << "\n";
            do
            {
                cout << "Ingrese el curso que desea buscar: ";
                cin >> curso;
            } while (tieneNum(curso) || ((curso).length()) <= 2 || errorCarga());
            for (int i = 0; i < n; i++)
            {
                if (curso == persona[i].carrera)
                {
                    cantEncontrados++;
                    cout << "Alumno: " << i + 1 << "\n";
                    cout << "Numero de Cedula: " << persona[i].cedula << "\n";
                    cout << "Nombre: " << persona[i].nombre << "\n";
                    cout << "Puntaje del Parcial 1: " << persona[i].parc_1 << "\n";
                    cout << "Puntaje del Parcial 2: " << persona[i].parc_2 << "\n";
                    cout << "Puntaje de Trabajo Practico: " << persona[i].tp << "\n";
                    cout << "====================================================="
                         << "\n";
                }
            }
            if (cantEncontrados != 0)
            {
                cout << "Se encontraron " << cantEncontrados << " personas que estudian " << curso << "\n";
                cantEncontrados = 0;
            }
            else
            {
                cout << "No se encontro ninguna persona que estudie " << curso << "\n";
                cantEncontrados = 0;
            }
            break;
        case 3:
            cout << "Opcion seleccionada: " << opcion << "\n";
            do
            {
                cout << "Ingrese Numero de Cedula a buscar: ";
                cin >> cedula;
            } while (cedula <= 0 || errorCarga());
            for (int i = 0; i < n; i++)
            {
                if (cedula == persona[i].cedula)
                {
                    cantEncontrados++;
                    cout << "Alumno: " << i + 1 << "\n";
                    cout << "Numero de Cedula: " << persona[i].cedula << "\n";
                    cout << "Nombre: " << persona[i].nombre << "\n";
                    cout << "Puntaje del Parcial 1: " << persona[i].parc_1 << "\n";
                    cout << "Puntaje del Parcial 2: " << persona[i].parc_2 << "\n";
                    cout << "Puntaje de Trabajo Practico: " << persona[i].tp << "\n";
                    cout << "====================================================="
                         << "\n";
                }
                else
                {
                    cout << "No se encontro a ninguna persona con el numero de cedula " << cedula << "\n";
                }
            }
            if (cantEncontrados != 0)
            {
                cout << "Se encontraron " << cantEncontrados << " personas. \n";
                cantEncontrados = 0;
            }
            else
            {
                cout << "No se encontro a ninguna persona con el numerode cedula " << cedula << "\n";
                cantEncontrados = 0;
            }
            break;
        case 4:
            cout << "Gracias por usar el programa.\n";
            break;
        default:
            cout << "ERROR!. La opcion seleccionada no es valida.\n";
            break;
        }
        cout << "Presiona una tecla para seguir.\n";
        getch();
    } while (opcion != 4);
}

void cantIng(int &n)
{
    cout << "Ingrese la cantidad de personas cuyos datos desea ingresar: ";
    cin >> n;
    while (n <= 0 || cin.fail())
    {
        cout << "Ha ocurrido un error con la carga de datos. Debe ingresarse un numero mayor a 0.\n";
        cout << "Vuelva a ingresar:";
        cin >> n;
        cin.clear();
        fflush(stdin);
    }
    return;
}

bool errorCarga(void)
{
    bool error = false;
    if (cin.fail())
    {
        cin.clear();
        fflush(stdin);
        error = true;
    }
    else
    {
        error = false;
    }
    return error;
}

bool tieneNum(string cadena)
{
    for(char letra : cadena)
    {
        if (isdigit(letra) != 0)
        {
            return true;
        }
    }
    return false;
}

int calificacion(int parc_1, int parc_2, int tp)
{
    int calificacion = 0, nota;
    calificacion = parc_1 + parc_2 + tp;
    if (calificacion >= 0 || calificacion <= 27)
    {
        nota = 1;
    }
    else if (calificacion >= 28 || calificacion <= 30)
    {
        nota = 2;
    }
    else if (calificacion >= 31 || calificacion <= 34)
    {
        nota = 3;
    }
    else if (calificacion >= 35 || calificacion <= 37)
    {
        nota = 4;
    }
    else if (calificacion >= 38 || calificacion <= 40)
    {
        nota = 5;
    }
}

void selectorOpcion(int &opcion)
{
    do
    {
        cout << "Presione la tecla que corresponde a la opcion que desea ejecutar: \n";
        cout << "1. Mostrar los datos ingresados en forma de tabla.\n";
        cout << "2. Ingresar un curso y filtrar la lista por el curso ingresado.\n";
        cout << "3. Ingresar la cedula de identidad de un estudiante y filtrar los datos del mismo.\n";
        cout << "4. Salir del Programa.\n";
        cout << "Opcion: ";
        cin >> opcion;
    } while (errorCarga() || opcion < 1 || opcion > 4);
}
