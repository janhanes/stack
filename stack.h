#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/* *** structures *********************************************************** */

/**@brief Struktur des Stacks.
 */
typedef struct intstack_t
{
    struct stack_element *first;
} intstack_t;

typedef struct stack_element
{
    int value;
    int isEmpty;
    struct stack_element* pred;
}stack_element;

/* *** interface ************************************************************ */

/**@brief Initialisiert einen neuen intstack.
 * @param self  der zu initialisierende intstack
 * @return 0, falls keine Fehler bei der Initialisierung aufgetreten sind,
 *      != 0, ansonsten
 */
extern int
stackInit(intstack_t* self)
{
    self->first = NULL;
    return 0;
}

/**@brief Gibt den intstack und alle assoziierten Strukturen frei.
 * @param self  der freizugebende intstack
 */
extern void
stackRelease(intstack_t* self)
{
    if(stackIsEmpty(self))
        return;
    else
    {
        while(!stackIsEmpty(self))
        {
            stackPop(self);
        }
        return;
    }
}

/**@brief Legt einen Wert auf den intstack.
 * @param self  der intstack
 * @param i     der Wert
 */
extern void
stackPush(intstack_t* self, int i)
{
    struct stack_element* help = malloc(sizeof(stack_element));
    help->value = i;
    help->isEmpty = 0;
    help->pred = self->first;
    self->first = help;
    return;
}

/**@brief Gibt das oberste Element des Stacks zurück.
 * @param self  der intstack
 * @return das oberste Element von \p self
 */
extern int
stackTop(const intstack_t* self)
{
    return self->first->value;
}

/**@brief Entfernt und liefert das oberste Element des Stacks.
 * @param self  der intstack
 * @return das oberste Element von \p self
 */
extern int
stackPop(intstack_t* self)
{
    if(stackIsEmpty(self))
    {
        printf("Error: stack is Empty");
        return 0;
    }
    int ans;
    stack_element *help = self->first;
    ans = stackTop(self);
    self->first = self->first->pred;
    free(help);
    return ans;
}

/**@brief Gibt zurück, ob der intstack leer ist.
 * @param self  der intstack
 * @return 0, falls nicht leer,
        != 0, falls leer
 */
extern int
stackIsEmpty(const intstack_t* self)
{
    if(self->first == NULL)
        return 1;
    return 0;
}

/**@brief Gibt den Inhalt des Stacks beginnend mit dem obersten Element auf der Standardausgabe aus.
 * @param self  der intstack
 */
extern void
stackPrint(const intstack_t* self)
{
    if(stackIsEmpty(self) != 0)
        return;
    stack_element *pntr = self->first;
    int h;
    while(pntr != NULL)
    {
        h = pntr->value;
        pntr = pntr->pred;
        printf("%d\n", h);
    }
    return;
}

#endif /* STACK_H_INCLUDED */
