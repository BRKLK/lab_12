#include <iostream>
#include <fstream>


int Count(std::string s, int i)
{
    if (s[i] == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + Count(s, i+1);
    }
}

void QuickSort(int arr[100], int start, int end)
{
    int j = start, i = j-1, pivot = end;
    

    if (end - start >= 1)
    {
        int tmp;
        while(j != pivot)
        {
            if (arr[j] < arr[pivot])
            {
                i++;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        
        pivot = i+1;
        tmp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = tmp;

        QuickSort(arr, start, pivot-1);
        QuickSort(arr, pivot+1, end);
    }

}

void FindPath(char field[100][100], int table[100][100], int n, int m, int step, int i, int j)
{
    if(step < table[i][j] && field[i][j] != '#')
    {
        table[i][j] = step;

        if(i+1 < n) {FindPath(field, table, n, m, step+1, i+1, j);}
        if(i-1 >= 0) {FindPath(field, table, n, m, step+1, i-1, j);}
        if(j+1 < m) {FindPath(field, table, n, m, step+1, i, j+1);}
        if(j-1 >= 0) {FindPath(field, table, n, m, step+1, i, j-1);}

        if(i+1 < n && j+1 < m) {FindPath(field, table, n, m, step+1, i+1, j+1);}
        if(i+1 < n && j-1 >= 0) {FindPath(field, table, n, m, step+1, i+1, j-1);}
        if(i-1 >= 0 && j+1 < m) {FindPath(field, table, n, m, step+1, i-1, j+1);}
        if(i-1 >= 0 && j-1 >= 0) {FindPath(field, table, n, m, step+1, i-1, j-1);}
        // FindPath(field, table, step+1)
    }
}


int main() 
{
    
    // 1
    std::string s;
    int counter = 0;

    std::cout << "Enter a string: "; 
    std::getline(std::cin, s);

    std::cout << Count(s, 0);


    // 2
    int arr[100], len;
    std::cout << "Enter a length of an array: "; std::cin >> len;
    for(int i = 0; i < len; i++)
    {
        std::cout << "Enter a number: "; std::cin >> arr[i];
    }

    QuickSort(arr, 0, len-1);

    // Printing an array
    std::cout << "Sorted Array:" << std::endl;
    for(int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }

    // 3

    char field[100][100];
    int table[100][100];
    int n, m, si, sj, ei, ej;
    std::ifstream in("field.txt");
    in >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            in >> field[i][j];
            table[i][j] = INT_MAX;
            if (field[i][j] == 'S') {si = i; sj = j;}
            if (field[i][j] == 'E') {ei = i; ej = j;}
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }


    FindPath(field, table, n, m, 0, si, sj);
    std::cout << table[ei][ej];




    return 0;
}

