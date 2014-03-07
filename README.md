FoxyC
=====

Adds class-oriented syntaxis to C, by using macro's only.

This project is mostly a hack to show what can be achieved using the C define structure in relation to the syntax. 

Requirements
===
Unfortunately, to be able to [seamlessly extend structs](http://modelingwithdata.org/pdfs/113-composition.pdf), we require Microsoft flavored anonymous struct. Thus, we require the flags `-fms-extensions -Wno-microsoft`.
Except for requiring anonymous structs, we aim to write standard C.

Examples
===
Node.h

```C
foxy(
    class (Node)
    {
        Node* root;
        Node* left;
        Node* right;
        Object value;
    }
)

foxy(
     class(RBNode extends Node)
     {
         enum{RED, BLACK} color;
     }
)
```
Node.c

```C
foxy(
    implementation(Node)
    {

    }
)

foxy(
    implementation(RBNode)
    {

    }
)
```
main.c
```
int main(int argc, const char * argv[]){
     Node* node = new_RBNode();//Currently new_RBNode is not yet implemented
     //Use node as you would normally use a struct...

     //Reflection class
     Class* class = node->class;//Equivalent to getClass(RBNode)
     
     //Copy the node
     Node* copy = malloc(class->size);
     memcpy(copy, node, class->size);
     
     //Outputs "Type of node = 'RBNode'"
     printf("Type of node = '%s'\n", class->name);
     
     //Outputs "Parent type of node = 'Node', grandparent = 'Object'"
     printf("Parent type of node = '%s', grandparent = '%s'\n",
         class->super->name,
         class->super->super->name);
}
```
