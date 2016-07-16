#include <string>
#include <iostream>

using namespace std;

/**
 * Esta función recibe una hilera y la convierte en un número entero
 * con signo.
 *
 * La hilera se descompone en dígitos y cada dígito se multiplica por su
 * base. Ejemplo 123 se descompone en 3*1 +  2*10 + 1*100. Si el número
 * tiene signo negativo se pone negativo el resultado.
 *
 * Tiempo de duración constante con base en la longitud de la hilera
*/
int stringToInteger(string str)
{
    string s = str;
    int resultado = 0;

    // Cada iteración aumenta *10
    int base = 1;

    for(int i = s.length()-1; i >= 0; i--)
    {
        // Resto '0' porque c me da el caracter ASCII del número
        char c = s[i];
        int digito = '0' - c;
        if(i == 0 && c == '-')
        {
            resultado = -resultado;
        }
        else
        {
            resultado += digito * base;
            base *= 10;
        }
    }
    return resultado;
}

int stringToInteger2(string str)
{
    const char * strPtr = str.c_str();
    int l = 0;
    int resultado = 0;

    while(*strPtr != 0)
    {
        ++strPtr;
        ++l;
    }
    --strPtr;
    --l;

    // Cada iteración aumenta *10
    int base = 1;

    for(int i = l; i >= 0; --i)
    {
        // Resto '0' porque c me da el caracter ASCII del número
        // La resta estaba al revés
        int digito =  (char)*strPtr - '0';

        if(i == 0 && *strPtr == '-')
        {
            resultado = -resultado;
        }
        else
        {
            resultado += digito * base;
            base *= 10;
        }
        --strPtr;
    }
    return resultado;
}

/**
 * Esta función toma un número entero con signo y lo
 * convierte a una hilera.
 *
 * Lo hace dividiendo entre las bases de diez del número y
 * luego sacándole los residuos entre 10 para tener los dígitos
 * que arman la hilera. Se podría decir que es un proceso a la inversa de
 * int stringToInteger(string).
 *
 * Tiempo de duración constante con base en el tamaño del número
 *
*/
string integerToString(int numero)
{
    string res("");
    int base = 1;
    int digito = 0;

    do
    {
        digito = numero / base % 10;

        // Si es un int negativo sus digitos son negativos y afecta al char
        if(digito < 0)
            digito = -digito;

        base *= 10;

        // como voy de der a izq, hago preppend en el string
        char c = digito +'0';
        res = res.insert(0, 1, c);
    }while(digito != 0);

    if(numero < 0)
    {
        res = res.insert(0, 1, '-');
    }
    return res;
}

string integerToString2(int numero)
{
    string res("");
    int base = 1;
    int digito = 0;

    do
    {
        // Moví el modulo de acá porque el do while
        // depende de la división
        digito = numero / base;

        // Si es un int negativo sus digitos son negativos y afecta al char
        if(digito < 0)
            digito = -digito;

        // If adicional para que no ponga un cero en el dígito más significativo
        if(digito != 0)
        {
            base *= 10;

            // como voy de der a izq, hago preppend en el string
            char c = (digito % 10) +'0';
            res = res.insert(0, 1, c);
        }
    }while(digito != 0);

    if(numero < 0)
    {
        res = res.insert(0, 1, '-');
    }
    return res;
}

// Casos de prueba
int main()
{
    string s1("4342");
    string s2("-42");

    cout << stringToInteger2(s1) << endl;
    // Debe imprimirse "4342"
    cout << stringToInteger2(s2) << endl;
    // Debe imprimirse "-42"

    int i1 = 654;
    int i2 = -2045;
    cout << integerToString2(i1) << endl;
    // Debe imprimirse "654"
    cout << integerToString2(i2) << endl;
    // Debe imprimirse "-8546"
    return 0;
}
