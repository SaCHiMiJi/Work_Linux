#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial
{
public:
    Poly_node *head = new Poly_node;
    int size;
    Polynomial()
    {
        /*
         WRITE YOUR CODE HERE
         */
        size = 0;
        head = NULL;
    }
    void addTerm(int coef, int exponent)
    {
        /*
         WRITE YOUR CODE HERE
         */
        if (size == 0)
        {
            // cout << "in 0\n";
            Poly_node *p = new Poly_node;
            p->coef = coef;
            p->exponent = exponent;
            head = p;
            size++;
        }
        else
        {

            Poly_node *p = new Poly_node;
            Poly_node *bf_p = new Poly_node;

            p->coef = coef;
            p->exponent = exponent;
            // cout << "coef :" << p->coef << "\nexponent :" << p->exponent << endl;
            if (size == 1)
            {
                bf_p = head;

                if (bf_p->exponent > exponent)
                {
                    // cout << "in 1\n";
                    bf_p->next = p;
                }
                else if (bf_p->exponent == exponent)
                {
                    bf_p->coef += coef;
                    delete p;
                }
                else
                {
                    // cout << "in 3\n";
                    head = p;
                    p->next = bf_p;
                }
            }
            else
            {

                Poly_node *af_p = new Poly_node;

                bf_p = head;
                af_p = head->next;
                while (bf_p != NULL)
                {
                    if (bf_p->next != NULL)
                    {
                        if (exponent > bf_p->exponent && exponent > af_p->exponent)
                        {
                            head = p;
                            p->next = bf_p;
                            break;
                        }
                        else if (exponent < bf_p->exponent && exponent > af_p->exponent)
                        {
                            bf_p->next = p;
                            p->next = af_p;
                            break;
                        }
                        else if (exponent == bf_p->exponent)
                        {
                            bf_p->coef += coef;
                            delete p;
                            break;
                        }
                        else if (exponent == af_p->exponent)
                        {
                            af_p->coef += coef;
                            delete p;
                            break;
                        }
                    }
                    else
                    {
                        bf_p->next = p;
                        break;
                    }
                    bf_p = bf_p->next;
                    af_p = af_p->next;
                }
            }
            size++;
        }
    }
    void printPolynomial()
    {
        cout << "[ ";
        Poly_node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->coef == 0)
            {
            }
            else
            {
                cout << ptr->coef << "X^{" << ptr->exponent << "} ";
            }
            ptr = ptr->next;
        }
        cout << "]\n";
    }
    void plus(Polynomial f2)
    {
        /*
         WRITE YOUR CODE HERE
         */
        // cout << "size : " << size << endl;
        Poly_node *p_f2 = f2.head;
        // cout << "head coef: " << f2.head->coef << endl;
        Poly_node *p = head;
        int j = 0;
        for (int i = 0; i < f2.size; i++)
        {
            // cout << "\n=========== i : " << i << " ===========" << endl;
            // cout << "P_f2 coef : " << p_f2->coef << endl;
            // cout << "P_f2 exponent : " << p_f2->exponent << endl;

            // Poly_node *p = head;
            while (p != NULL)
            {
                // cout << "\nj : " << j << endl;
                // cout << "size : " << size << endl;
                // cout << "p_f2 exponent: " << p_f2->exponent << endl;
                // cout << "p exponent: " << p->exponent << endl;

                if (p_f2->exponent > p->exponent)
                {
                    Poly_node *add_node = new Poly_node;
                    add_node->exponent = p_f2->exponent;
                    add_node->coef = p_f2->coef;
                    // cout << "\nadd first node" << endl;
                    if (size == 2)
                    {
                        p = head;
                        Poly_node *p_next = p->next;
                        // cout << "size : " << size << endl;
                        // cout << "p next : " << p_next->exponent << endl;
                        // cout << "p coef: " << p->coef << endl;
                        // cout << "p exponent: " << p->exponent << endl;
                        
                        if (p_f2->exponent > p_next->exponent)
                        {
                            // cout << "add 1" << endl;
                            head->next = add_node;
                            add_node->next = p_next;
                            size++;
                            break;
                        }
                    }
                    else if (size > 2)
                    {
                        Poly_node *p_next = p->next;
                        // cout << "size : " << size << endl;
                        // cout << "p next : " << p_next->exponent << endl;
                        // cout << "p coef: " << p->coef << endl;
                        // cout << "p exponent: " << p->exponent << endl;
                        
                        if (p_f2->exponent > p_next->exponent)
                        {
                            // cout << "add 1" << endl;
                            head->next = add_node;
                            add_node->next = p_next;
                            size++;
                            break;
                        }
                    }
                    
                    else if (p == head)
                    {
                        // cout << "add head" << endl;
                        head = add_node;
                        add_node->next = p;
                        size++;
                        break;
                    }
                }
                else if (p_f2->exponent == p->exponent) // exponent is equl
                {
                    // cout << "in plus" << endl;
                    p->coef += p_f2->coef;
                    break;
                }
                else if (p_f2->exponent < p->exponent && p->next != NULL)
                {
                    // cout << "in add_node" << endl;
                    Poly_node *p_next = p->next;
                    Poly_node *add_node = new Poly_node;

                    add_node->exponent = p_f2->exponent;
                    add_node->coef = p_f2->coef;
                    // cout<<"add_node : \n"<<add_node->coef<<endl<<add_node->exponent<<endl;

                    if (p_f2->exponent > p_next->exponent)
                    {
                        // cout << "add 1" << endl;
                        p->next = add_node;
                        add_node->next = p_next;
                        size++;
                        break;
                    }
                }
                else if (p->next == NULL && size == j + 1)
                {
                    // cout << "add last node" << endl;
                    Poly_node *add_node = new Poly_node;

                    add_node->exponent = p_f2->exponent;
                    add_node->coef = p_f2->coef;

                    // cout << "add 2" << endl;
                    p->next = add_node;
                    add_node->next = NULL;
                    size++;
                    break;
                }

                p = p->next;
                j++;
            }
            p_f2 = p_f2->next;
        }
    }
    void minus(Polynomial f2)
    {
        /*
         WRITE YOUR CODE HERE
         */
        // cout << "size : " << size << endl;
        Poly_node *p_f2 = f2.head;
        // cout << "head coef: " << f2.head->coef << endl;
        Poly_node *p = head;
        int j = 0;
        for (int i = 0; i < f2.size; i++)
        {
            // cout << "\n=========== i : " << i << " ===========" << endl;
            // cout << "P_f2 coef : " << p_f2->coef << endl;
            // cout << "P_f2 exponent : " << p_f2->exponent << endl;

            // Poly_node *p = head;
            while (p != NULL)
            {

                // cout << "\nsize : " << size << endl;
                // cout << "j : " << j << endl;

                // cout << "p_f2 exponent: " << p_f2->exponent << endl;
                // cout << "p exponent: " << p->exponent << endl;
                if (p_f2->exponent > p->exponent)
                {
                    Poly_node *add_node = new Poly_node;
                    add_node->exponent = p_f2->exponent;
                    add_node->coef = p_f2->coef;
                    // cout << "\nadd first node" << endl;
                    if (size == 2)
                    {
                        p = head;
                        Poly_node *p_next = p->next;
                        // cout << "size : " << size << endl;
                        // cout << "p next : " << p_next->exponent << endl;
                        // cout << "p coef: " << p->coef << endl;
                        // cout << "p exponent: " << p->exponent << endl;
                        
                        if (p_f2->exponent > p_next->exponent)
                        {
                            // cout << "add 1" << endl;
                            head->next = add_node;
                            add_node->next = p_next;
                            size++;
                            break;
                        }
                    }
                    else if (size > 2)
                    {
                        Poly_node *p_next = p->next;
                        // cout << "size : " << size << endl;
                        // cout << "p next : " << p_next->exponent << endl;
                        // cout << "p coef: " << p->coef << endl;
                        // cout << "p exponent: " << p->exponent << endl;
                        
                        if (p_f2->exponent > p_next->exponent)
                        {
                            // cout << "add 1" << endl;
                            head->next = add_node;
                            add_node->next = p_next;
                            size++;
                            break;
                        }
                    }
                    
                    else if (p == head)
                    {
                        // cout << "add head" << endl;
                        head = add_node;
                        add_node->next = p;
                        size++;
                        break;
                    }
                }
                else if (p_f2->exponent == p->exponent) // exponent is equl
                {
                    // cout << "in Minus" << endl;
                    p->coef -= p_f2->coef;
                    break;
                }
                else if (p_f2->exponent < p->exponent && p->next != NULL)
                {
                    // cout << "in add_node" << endl;
                    Poly_node *p_next = p->next;
                    Poly_node *add_node = new Poly_node;

                    add_node->exponent = p_f2->exponent;
                    add_node->coef = -1 * p_f2->coef;
                    // cout<<"add_node : \n"<<add_node->coef<<endl<<add_node->exponent<<endl;

                    if (p_f2->exponent > p_next->exponent)
                    {
                        // cout << "add 1" << endl;
                        p->next = add_node;
                        add_node->next = p_next;
                        size++;
                        break;
                    }
                }
                else if (p->next == NULL && size == j + 1)
                {
                    // cout<<"add last node"<<endl;
                    Poly_node *add_node = new Poly_node;

                    add_node->exponent = p_f2->exponent;
                    add_node->coef = -1 * p_f2->coef;

                    // cout << "add 2" << endl;
                    p->next = add_node;
                    add_node->next = NULL;
                    size++;
                    break;
                }

                p = p->next;
                j++;
            }
            p_f2 = p_f2->next;
        }
    }
};
