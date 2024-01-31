#include<bits/stdc++.h>
using namespace std;
struct node{
        int data;
        node *left;
        node *right;
};
node *root=NULL;
queue<node*>q;
void ins_perf(int x)
{
    node *curr=root,*temp;
    temp=new node();
    temp->data=x;
    if(curr==NULL)
    {
        q.push(temp);
        root=temp;
    }
    else 
    {
        q.push(temp);
        if(q.front()->left==NULL)
        {
            q.front()->left=temp;
        }
        else
        {
            q.front()->right=temp;
            q.pop();
        }
    }

}
void BST_ins(int v)
{
    node *curr=root,*temp,*prev=root;
    temp=new node();
    temp->data=v;
    temp->left=NULL;
    temp->right=NULL;
    if(curr==NULL)
    {
        root=temp;
    }
    else
    {
        while(curr!=NULL)
        {
            prev=curr;
            if(curr->data<v)
            {
                curr=curr->right;
            }
            else
            curr=curr->left;

        }
        if(prev->data<v)
        {
            prev->right=temp;

        }
        else 
        prev->left=temp;

    }


}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int min()
{
    node *curr=root;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr->data;
}
int max()
{
    node *curr=root;
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr->data;
}
void del(int v)
{
    node *curr=root,*prev=root;
    while(curr!=NULL)
    {
        
        if(curr->data==v)
        break;
        prev=curr;
        if(curr->data<v)
        {
           curr= curr->right;
        }
        else
        curr=curr->left;
    }
    if(curr==NULL)
    {
        cout<<"NOT f";
        return;
    }
    if(curr->left==NULL && curr->right==NULL)
    {
        if(prev->left==curr)
        prev->left=NULL;
        else
        prev->right=NULL;

    }
    else if(curr->left==NULL || curr->right==NULL)
    {
        node *child=curr;
        if(curr->left==NULL)
        child=curr->right;
        else
        child=curr->left;
        if(prev->right==curr)
        prev->right=child;
        else
        prev->left=child;

    }
    else
    {
        node *temp=curr;
        curr=curr->right;
        while(curr->left!=NULL)
        {
            prev=curr;
            curr=curr->left;
        }
        temp->data=curr->data;
        prev->left=curr->right;

    }
    
}

int main()
{
    for(int i=0;i<11;i++)
    {
        int x;
        cin>>x;
        BST_ins(x);
        //ins_perf(x);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;
    cout<<min()<<endl;
    cout<<max()<<endl;
    int x;
    cin>>x;
    del(x);
    cout<<endl;
    inorder(root);
    


}
//100 50 120 150 200 160 180 300 320 250 270