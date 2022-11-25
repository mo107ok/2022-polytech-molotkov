void insertion(int arr[], int n_arr[], int size, int a, int b)
{

for(int i=0; i <= size; i++){

if(i==b){

    n_arr[i]=a;

  }

if(i<b){

    n_arr[i]=arr[i];

  }

if(i>b){

    n_arr[i]=arr[i-1];

  }

 }

}