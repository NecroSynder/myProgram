// Hashing Problem #1
// Authors:  
//          GC Neal Christian S. Clarin
//          Vince Japheth F. Loable

#include <iostream>
#include <string>
using namespace std;

int safeMod(int dividend, int divisor){
    return (dividend % divisor + divisor) % divisor;
}

void linearHashing(int table[], int table_size, int arr[], int arr_size, int &probes)
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = -1;
    }

    cout << "Linear Hashing" << endl;
    for (int iterX = 0; iterX < arr_size; iterX++)
    {
        int hk = safeMod(arr[iterX], table_size);
        if (table[hk] == -1) {
            table[hk] = arr[iterX];
        } else {
            for (int iterY = 0; iterY < table_size; iterY++)
            {
                int i = 1 + iterY;
                int index = safeMod(hk + i, table_size);
                if (table[index] == -1)
                {
                    probes = probes + 1;
                    table[index] = arr[iterX];
                    break;
                }
            }
        }
    }
    for (int iterZ = 0; iterZ < table_size; iterZ++)
    {
        string result = "";
        if (table[iterZ] == -1){
            result = "_";
        }else{
            result = to_string(table[iterZ]);
        }
        cout << result << " ";
    }
    cout << "\nTotal Probes: " << probes << endl;
    probes = 0;
    cout << "\n" << endl;
}

void quadraticHashing(int table[], int table_size, int arr[], int arr_size, int &probes)
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = -1;
    }

    cout << "Quadratic Hashing" << endl;
    for (int iterX = 0; iterX < arr_size; iterX++)
    {
        int hk = safeMod(arr[iterX], table_size);
        if (table[hk] == -1) {
            table[hk] = arr[iterX];
        } else {
            for (int iterY = 0; iterY < table_size; iterY++)
            {
                int i = 1 + iterY;
                int index = safeMod(hk+(i*i), table_size);
                if (table[index] == -1)
                {
                    probes = probes + 1;
                    table[index] = arr[iterX];
                    break;
                }
            }
        }
    }
    for (int iterZ = 0; iterZ < table_size; iterZ++)
    {
        string result = "";
        if (table[iterZ] == -1)
        {
            result = "_";
        }
        else
        {
            result = to_string(table[iterZ]);
        }
        cout << result << " ";
    }
    cout << "\nTotal Probes: " << probes << endl;
    probes = 0;
    cout << "\n"
         << endl;
}

void doubleHashing(int table[], int table_size, int arr[], int arr_size, int &probes)
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = -1;
    }

    cout << "Double Hashing" << endl;
    for (int iterX = 0; iterX < arr_size; iterX++)
    {
        int hk = safeMod(arr[iterX], table_size);
        if (table[hk] == -1){
            table[hk] = arr[iterX];
        }
        else
        {
            for (int iterY = 0; iterY < table_size; iterY++)
            {
                int dk = safeMod(13 - arr[iterX], 13);
                int index = safeMod(dk+(iterY*dk),17); 
                if (table[index] == -1)
                {
                    probes = probes + 1;
                    table[index] = arr[iterX];
                    break;
                }
            }
        }
    }
    for (int iterZ = 0; iterZ < table_size; iterZ++)
    {
        string result = "";
        if (table[iterZ] == -1)
        {
            result = "_";
        }
        else
        {
            result = to_string(table[iterZ]);
        }
        cout << result << " ";
    }
    cout << "\nTotal Probes: " << probes << endl;
    probes = 0;
    cout << "\n"
         << endl;
}

int main()
{
    int probes = 0;
    int arr[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int arr_size = 10;

    int table_size = 17;
    int hash_table[17];

    linearHashing(hash_table, table_size, arr, arr_size, probes);
    quadraticHashing(hash_table, table_size, arr, arr_size, probes);
    doubleHashing(hash_table, table_size, arr, arr_size, probes);
    return 0;
}