    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    
    int quicksort(int s[],int l,int r)
    {

        
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quicksort(s, l, i - 1); // 递归调用  
        quicksort(s, i + 1, r);  
    }  
                   
                   
        return 0;
    }
    int main(int argc, char *argv[])
    {
        int p[10]={4,2,6,8,10,3,12,34,23,22};
        quicksort(p,0,9);

        for(int i=0;i<10;i++){
                cout<<p[i]<<',';
        }
        cout<<endl;        
        system("PAUSE");
        return EXIT_SUCCESS;
    }
