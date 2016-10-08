#include <stdio.h>


     struct nodes
  {
    int level;
    int child1;
    int child2;
    int isRoot;
    float prob;
    int parent;
  };

void ordenar(int input[],int tamanho,struct nodes node [10]);

int main(void)
{
    float vetor[11] = {10,9,8,7,6.5,5.4,4,3,2,1,54};
    int tamanho = 11;
    int i,j,r,aux;

    int freq[4]={2, 2, 2, 4};
    float prob[4]={0.2,0.2, 0.4, 0.2};


int  nodesremaining=1;

struct  nodes node[10];


for(i=0; i <4; i++) 
{  
node[i].level=0;
node[i].isRoot=0;
node[i].prob=prob[i];
node[i].child1=999;
node[i].child2=999;
}


int node_control=4;
int priority_vector[5];
float prob_vector[4];
int priority_vector2[4];

int iteration=1;

for(i=0; i <5; i++) 
{  
    priority_vector[i]=i;
}

int a[5]={4,3,2,1,0};

node[0].prob=1;
node[1].prob=4;
node[2].prob=2;
node[3].prob=7;
node[4].prob=9;


ordenar(priority_vector,5,node);



printf("posicionamento");
    for(r = 0; r < 5; ++r)
    {
        printf("%d\n",priority_vector[r]);
    }



for(i=0; i <4; i++) 
{  
    priority_vector[i]=prob_vector[i];
}






node[node_control].prob   =    node[priority_vector[0]].prob + node[priority_vector[1]].prob;
node[node_control].child1 =    priority_vector[0];
node[node_control].child2 =    priority_vector[1];
node[node_control].level  =    0;


priority_vector2[0]=node_control;
priority_vector[0]=priority_vector[2];
priority_vector[1]=priority_vector[3];



node[5].prob   =    node[priority_vector[0]].prob + node[priority_vector[1]].prob;
node[5].child1 =    priority_vector[0];
node[5].child2 =    priority_vector[1];
node[5].level  =    0;


priority_vector[0]=5;
priority_vector[1]=priority_vector[2];



for(i=0; i <2; i++) 
{  
    priority_vector[i]=prob_vector[i];
}

node[6].prob   =    node[priority_vector[0]].prob + node[priority_vector[1]].prob;
node[6].child1 =    priority_vector[0];
node[6].child2 =    priority_vector[1];
node[6].level  =    0;



printf("prob node 1 ");
printf("%f\n",node[5].prob);

printf("prob position");
for(r = 0; r < 4; ++r)
    {
        printf("%d\n",priority_vector[r]);
    }


//ordenar(vetor,11);




}


void ordenar(int input[],int tamanho,struct nodes node[10]){
int i,j;
int aux;
//int input[10];


    for(i=tamanho-1; i >= 1; i--) 
    {  
        for(j=0; j < i ; j++) 
        {
            if(node[j].prob>node[j+1].prob) 
            {
                aux = input[j];
                input[j] = input[j+1];
                input[j+1] = aux;
            }
        }
    }


        //printf("vetor ordenado");
    for(i = 0; i < 10; ++i)
    {
       // printf("%f\n",vetor[i]);
    }
//printf("entrada");
    for(i = 0; i < 10; ++i)
    {
     //   printf("%f\n",input[i]);
    }


    for(i=0; i <tamanho; i++) 
        {  

        for(j=0; j <tamanho; j++) 
            {  
              // if (input[i]==vetor[j]) { input[i]=j; vetor[j]=999; break;   }

            }
        }

    }