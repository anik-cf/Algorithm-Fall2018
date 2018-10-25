#include<iostream>
#include<cstdlib>
#include <iomanip>

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;


typedef struct{
    int itemId;
    double profitAmount;
    double weight;
    double profitPerUnit;
}Product;

Product *a;
Product temp;


void bubble_sort(int n)
{
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            //sorting based on profit Per unit
            if(a[i].profitPerUnit < a[j].profitPerUnit){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void inputHandling(int n){
    cout << "Item id [space] Profit [space] Weight [enter]" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a[i].itemId >> a[i].profitAmount >> a[i].weight;
        a[i].profitPerUnit = a[i].profitAmount / a[i].weight;
    }

}

void printItems(int n)
{
    cout << endl;
    cout << "Retrieved list of items: ------" << endl;
    cout << endl;
    cout << setw(5) << "ItemId ";
    cout << setw(5) << "Profit ";
    cout << setw(5) << "Weight ";
    cout << setw(10) << "PPU " << endl;
    for(int i=0; i<n; i++)
    {
        cout << setw(5) << a[i].itemId << "   ";
        cout << setw(5) << a[i].profitAmount << "   ";
        cout << setw(5) << a[i].weight << "   ";
        cout << setw(10) << a[i].profitPerUnit << endl;
    }
    cout << endl << "---- End of entries ----" << endl << endl;
}

int main()
{

    //READ("in.txt");
    //WRITE("out.txt");

    /*
    Sample Test Case:
    5
    1 20 5
    2 15 5
    3 10 2
    4 21 3
    5 14 7
    */

    int n;
    cout << "Enter count of entries to store: " << endl;
    cin >> n;

    a = (Product *) malloc(n*sizeof(Product));

    inputHandling(n);

    // Printing the items before sorting
    printItems(n);

    bubble_sort(n);

    cout << "Sorted based on ProfitPerUnit" << endl;

    //Printing the items after sorting
    printItems(n);

}
