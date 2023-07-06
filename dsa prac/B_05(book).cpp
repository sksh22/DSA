/*A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space requirements 
of your method. */

#include<iostream>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node*child[10];

}*root;

class tree
{
    public:
        void create();
        void display(node*r1);
        tree()
        {
            root=NULL;
        }
};

void tree:: create()
{
    int tch,i,j,k;
    root=new node;
    cout<<"enter name of book:"<<endl;
    cin>>root->label;
    cout<<"enter number of chapters"<<endl;
    cin>>tch;
    root->ch_count=tch;
    for(i=0;i<tch;i++)
    {
        root->child[i]=new node;
        cout<<"enter chapter"<<i+1<<"name"<<endl;
        cin>>root->child[i]->label;
        cout<<"enter number sections:"<<endl;
        cin>>root->child[i]->ch_count;
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"section"<<j+1<<"name"<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"enter number of subsections:"<<endl;
            cin>>root->child[i]->child[j]->ch_count;
            for(k=0;k<root->child[i]->child[j]->ch_count;k++)
            {
                root->child[i]->child[j]->child[k]=new node;
                cout<<"subsection "<<k+1<<"name"<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
            }

        }

    }
}

void tree ::display(node *r1)
{
   int tch,i,j,k;
   if(r1!=NULL)
   {
    cout<<"name of book;"<<endl;
    cout<<r1->label<<endl;
      cout<<"book hierarchy"<<endl;
      tch=r1->ch_count;
      for(i=0;i<tch;i++)
      {
        cout<<"chapter"<<i+1<<endl;
        cout<<r1->child[i]->label<<endl;
        for(j=0;j<r1->child[i]->ch_count;j++)
        {
            cout<<"sections"<<j+1<<endl;
            cout<<r1->child[i]->child[j]->label<<endl;;
            for(k=0;k<r1->child[i]->child[j]->ch_count;k++)
            {
                cout<<"subsections"<<k+1<<endl;
                cout<<r1->child[i]->child[j]->child[k]->label<<endl;
            }
        }

      }

   }
}


int main()
{
    int ch;
    tree t;
    while(1)
    {
        cout<<"1.create"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.exit"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"enter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.create();
                break;

            case 2:
                t.display(root);
                break;

            default:
                cout<<"invalid choice"<<endl;
                break;
        }
    }
    return 0;
}