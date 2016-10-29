#include <stdio.h>
#include <string.h>

struct nodes
{   int child0;
    int child1;
    int isRoot;
    float prob;
    int parent;
};

void ordenar(float input[],int p_vector [],int tamanho,struct nodes * node );

int main(void)
{
    int i;
    
    float prob[8]={0.2,0.2,0.15,0.1,0.1,0.1,0.1,0.05};
    int  nodesremaining=8;
    struct  nodes node[20];
    
    
    for(i=0; i <8; i++)
    {
        node[i].isRoot=0;
        node[i].prob=prob[i];
        node[i].child0=999;
        node[i].child1=999;
    }
    

    
    int node_control=8;
    int priority_vector[8];
    float prob_vector[8];
    
    for(i=0; i <8; i++)
    {
        priority_vector[i]=i;
        prob_vector[i]=prob[i];
    }
    
    for(i=0; i <8; i++)
    {
        node[i].prob=prob[i];
    }
    
    
    ordenar(prob_vector,priority_vector,8,node);
    
    while(nodesremaining>1){
        
        node[node_control].prob   =    node[priority_vector[0]].prob + node[priority_vector[1]].prob;
        node[node_control].child0 =    priority_vector[1];
        node[node_control].child1 =    priority_vector[0];
        
        node[priority_vector[0]].parent=node_control;
        node[priority_vector[1]].parent=node_control;
        
        
        if(nodesremaining==2) node[node_control].isRoot=1;
        
        if(nodesremaining==3){
            
            priority_vector[1]=priority_vector[2];
            priority_vector[0]=node_control;
        }
        else{
            
            
            priority_vector[1]=priority_vector[2];
            priority_vector[2]=priority_vector[3];
            priority_vector[3]=priority_vector[4];
            priority_vector[4]=priority_vector[5];
            priority_vector[5]=priority_vector[6];
            priority_vector[6]=priority_vector[7];
            
            priority_vector[0]=node_control;
            
            for(i=0; i <8; i++)
            {
                prob_vector[i]=node[priority_vector[i]].prob;
            }
            
            ordenar(prob_vector,priority_vector, nodesremaining-1,node);
            
        }
        nodesremaining--;
        node_control++;
        
    }
    
    char codigo[8][5];
    
    int pos;
    int father,j,k;
    
    
    
    int no=0;
    for(i=0; i<8; i++)
    {   pos=3;
        no=i;
        while (1){
            father=node[no].parent;
            
            if(node[father].child0==no) {strcat(codigo[i],"0"); }
            if(node[father].child1==no) {strcat(codigo[i],"1"); }
            
            if(node[father].isRoot==1) {
                break;}
            pos--;
            
            no=father;
        }
               
        
    }
   
    char temp;
    for(k=0; k<8; k++)
    {
    i=0;
    j = strlen(codigo[k]) - 1;
    
    while (i < j) {
        temp = codigo[k][i];
        codigo[k][i] = codigo[k][j];
        codigo[k][j] = temp;
        i++;
        j--;
    }
        
        printf("%d - Huffman Code ",k);
        printf("%s\n",codigo[k]);
   
    }
    
    

    
    FILE *fp;
    
    fp = fopen("test.dot", "w+");
    
    fprintf(fp, "digraph G { edge [label=0]; ");
    
    
    for(i = 0; i < 8; ++i)
    {
        
        fprintf(fp, "%d [shape=record,label=\" Simbolo: %d |P= %.2f |%s  \"];",i,i, node[i].prob,codigo[i]);
        
    }
    
    
    
    for(i = 14; i > 7; --i)
    {
        fprintf(fp, "%d [label=%.2f];",i, node[i].prob);
    }
    for(i = 14; i > 7; --i)
    {
        
        fprintf(fp, "%d -> %d ; %d -> %d [label=1] ;",i, node[i].child0,i,node[i].child1);
    }
    
    
    fprintf(fp, "  labelloc=\"t\";label=\"Arvore Huffman \";  }");
    fclose(fp);
    
    
      
}


void ordenar(float input[],int p_vector [],int tamanho,struct nodes *node){
    int i,j;
    float aux;
    int aux2;
    
    
    for(i=tamanho-1; i >=1; i--)
    {
        for(j=0; j <i; j++)
        {
            if(input[j]>input[j+1])
            {
                aux = input[j]; aux2=p_vector[j];
                input[j] = input[j+1]; p_vector[j]=p_vector[j+1];
                input[j+1] = aux; p_vector[j+1]=aux2;
            }
        }
    }
    
    
}
