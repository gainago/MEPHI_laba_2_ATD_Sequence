#include <iostream>
#include "AllRequiredHeaders.h"
#include "scanfint.cpp"
template <typename T>
void PrintSequence(Sequence<T> *seq)
{
    std::cout << "Result: " << std::endl;
    for (int i = 0; i < seq->GetLength(); i++)
    {
        std::cout << (*seq)[i] << " ";
    }
    std::cout << "\n";
}

template<typename Type>
void Show_Table_Massive(MutableListSequence<Sequence<Type>*> const & TableMassive)
{
    for(int i = 0;i < TableMassive.GetLength();i++)
    {   MutableListSequence<Type>* mut = dynamic_cast<MutableListSequence<Type>*>(TableMassive.Get(i));
        if(mut != 0)
        printf("массив %d MutableListSequence\n",i);
        ImmutableListSequence<Type>* immut = dynamic_cast<ImmutableListSequence<Type>*>(TableMassive.Get(i));
        if(immut != 0)
        printf("массив %d ImmutableListSequence\n",i);
        ArraySequence<Type>* arr = dynamic_cast<ArraySequence<Type>*>(TableMassive.Get(i));
        if(arr != 0)
        printf("массив %d ArraySequence\n",i);
        //TableMassive.GetIndex(i)->Print();
        PrintSequence(TableMassive.Get(i));
    }
}
template <typename Type>
void User()
{   
    //Type arr[10] = {1,3,5,7,9,2,4,6,8,10};
    //Type arr[5] = {1,3,5,7,9,2,4,6,8,10};

   int operation = 1;
   MutableListSequence<Sequence<Type>*> TableMassive;
   //TableMassive.Append(new ImmutableListSequence<Type>(arr,10));
   while(operation)
   {

    printf("Выберите Действие:\n\
            1. получить элемент по индексу \n\
            2. получить длину\n\
            3. добавить элемент вначало\n\
            4. добавить элемент в конец\n\
            5. получить подпоследовательность\n\
            6. соединить списки элементов\n\
            7. создать MutableListSequence\n\
            8. создать ImmutableListSequence\n\
            9. создать ArraySequence\n\
            0. выйти\n");
            Show_Table_Massive(TableMassive);
    int flag = -1;
    do{
        //flag = scanfint(&operation);
        flag = scanf("%d",&operation);
    }while(flag == 0 || operation < 0 || operation > 9);
    switch (operation)
    {
    case 1:
    {   
        if(TableMassive.GetLength() == 0) 
            {
                printf("у вас нет ни одного созданного массива\n");
                break;
            }
        printf("выберите массив");
        int n = 0,flag = -1;
         do{
            flag = scanfint(&n);
        }while(flag == -1|| n >= TableMassive.GetLength());
        flag = -1;
        int index = 0;
        printf("введите номер элемента\n");
        do{
            flag = scanfint(&index);
        }while(flag == -1|| index >= (TableMassive.Get(n))->GetLength());
        std :: cout << "element is " << TableMassive.Get(n)->Get(index) <<std:: endl;
        //Print(TableMassive.GetIndex(n)->GetIndex(index));
    }
        break;
    case 2:
        {
            if(TableMassive.GetLength() == 0)
            {
                printf("у вас нет ни одного созданного массива\n");
                break;
            }
            printf("выберите массив");
            int n = 0,flag = -1;
            do{
                flag = scanfint(&n);
            }while(flag == -1|| n >= TableMassive.GetLength());
            std :: cout << "size is " << TableMassive.Get(n)->GetLength() <<std:: endl;
        }
        break;
    case 3:
            {
                if(TableMassive.GetLength() == 0)
                {
                    printf("у вас нет ни одного созданного массива\n");
                    break;
                }
                printf("выберите массив\n");
                int n = 0,flag = -1;
                do{
                    flag = scanfint(&n);
                }while(flag == -1|| n >= TableMassive.GetLength());
                printf("введите элемент\n");
                Type elem;
                std:: cin >> elem;
                //Scanf(&elem);
                Sequence<Type>* ptr = TableMassive.Get(n)->Prepend(elem);
                //ptr->Print();
                PrintSequence(ptr);
            }
            break;
    case 4:
             {
                if(TableMassive.GetLength() == 0)
                {
                    printf("у вас нет ни одного созданного массива\n");
                    break;
                }
                printf("выберите массив\n");
                int n = 0,flag = -1;
                do{
                    flag = scanfint(&n);
                }while(flag == -1|| n >= TableMassive.GetLength());
                printf("введите элемент\n");
                Type elem;
                std:: cin >> elem;
                //Scanf(&elem);
                Sequence<Type>* ptr = TableMassive.Get(n)->Append(elem);
                PrintSequence(ptr);
            }
            break;
    case 5:
             {
                if(TableMassive.GetLength() == 0)
                {
                    printf("у вас нет ни одного созданного массива\n");
                    break;
                }
                printf("выберите массив\n");
                int n = 0,flag = -1;
                do{
                    flag = scanfint(&n);
                }while(flag == -1|| n >= TableMassive.GetLength());
                printf("введите номер левой границы\n");
                int left = 0;
                flag = -1;
                do{
                    flag = scanfint(&left);
                }while(flag == -1|| left < 0);
                printf("введите номер правой границы\n");
                int right = 0;
                flag = -1;
                do{
                    flag = scanfint(&right);
                }while(flag == -1 || right > TableMassive.Get(n)->GetLength());
                Sequence<Type>* ptr;
                try{
                    ptr = TableMassive.Get(n)->GetSubSequence(left,right);
                    //ptr->Print();
                    PrintSequence(ptr);
                }
                catch(char const* str)
                {
                    std:: cout << str;
                }
                
            }
            break;
        case 6:
                {
                if(TableMassive.GetLength() < 2)
                {
                    printf("у вас нет двух миссивов \n");
                    break;
                }
                printf("выберите массив в который добавятся элементы\n");
                int mas1 = 0,flag = -1;
                do{
                    flag = scanfint(&mas1);
                }while(flag == -1|| mas1 >= TableMassive.GetLength());
                printf("выберите массив из которого элементы скопируются\n");
                int mas2 = 0;
                flag = -1;
                do{
                    flag = scanfint(&mas2);
                }while(flag == -1|| mas2 >= TableMassive.GetLength());
                Sequence<Type>* ptr;
                
                    ptr = TableMassive.Get(mas1)->Concat(*TableMassive.Get(mas2));
                   // ptr->Print();
                   PrintSequence(ptr);
            }
            break;
        case 7:
            {   
                printf("введите размер массива\n");
                int size = 0,flag = -1;
                do{
                    flag = scanfint(&size);
                }while(flag == -1);
                Type array[size];
                printf("введите %d элементов\n",size);
                for(int i = 0;i < size;i++)
                {
                    std:: cin >> array[i];
                    //Scanf(&array[i]);
                }
                LinkedList<Type> LL(array,size);
                TableMassive.Append(new MutableListSequence<Type>(LL));
            }
            break;
        case 8:
            {   
                printf("введите размер массива\n");
                int size = 0,flag = -1;
                do{
                    flag = scanfint(&size);
                }while(flag == -1);
                Type array[size];
                printf("введите %d элементов\n",size);
                for(int i = 0;i < size;i++)
                {
                    std:: cin >> array[i];
                    //Scanf(&array[i]);
                }
                TableMassive.Append(new ImmutableListSequence<Type>(array,size));
            }
            break;
        case 9:
            {   
                printf("введите размер массива\n");
                int size = 0,flag = -1;
                do{
                    flag = scanfint(&size);
                }while(flag == -1);
                Type array[size];
                printf("введите %d элементов\n",size);
                for(int i = 0;i < size;i++)
                {
                    std:: cin >> array[i];
                    //Scanf(&array[i]);
                }
                TableMassive.Append(new MutableArraySequence<Type>(array,size));
            }
            break;
        /*case 10:
            {
                if(TableMassive.GetLength() == 0)
                {
                    printf("у вас нет ни одного созданного массива\n");
                    break;
                }
               
                printf("выберите массив\n");
                int n = 0,flag = -1;
                do{
                    flag = scanfint(&n);
                }while(flag == -1|| n >= TableMassive.GetLength());
                 if(TableMassive.Get(n)->GetLength() == 0)
                {
                    printf("у вас нет элементов\n");
                        break;
                }
                printf("введите номер элемента который хотите удалить\n");
                int index = 0;
                flag = -1;
                do{
                    flag = scanfint(&index);
                }while(flag == -1|| index >= TableMassive.Get(n)->GetLength() || index < 0);
                Sequence<Type>* ptr = TableMassive.Get(n)->DeleteIndex(index);
                //ptr->Print();
                PrintSequence(ptr);
            }*/
    
    default:
        break;
    }
   }


}