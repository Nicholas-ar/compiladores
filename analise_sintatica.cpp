#include <iostream>
#include <string>

class tk{
    string categ;
};

void fPgm()
{
    fLSent();
    if (tk.categ == 'Pt')
    {
        tk.next();
        if (tk.categ == 'EOF')
        {
            return;
        }
        else
            throw Error("'EOF' esperado", tk);
    }
    else
        throw Error("'.' esperado", tk);
}

void fLSent()
{
    fSent();
    fLSentr();
}

void fLSentr()
{
    if (tk.categ == 'PtVg')
    {
        tk.next();
        fSent();
        fLSentr();
    }
}

void fSent()
{
    if (tk.categ == 'Se')
    {
        tk.next();
        fEb();
        if (tk.categ == 'Então')
        {
            tk.next();
            fLSent();
            if (tk.categ == 'Senão')
            {
                tk.next();
                fLSent();
                if (tk.categ == 'Fim')
                {
                    tk.next();
                    return;
                }
                else
                    throw Error("'Fim' esperado", tk);
            }
            else if (tk.categ == 'Fim')
            {
                tk.next();
                return;
            }
            else
            {
                throw Error("'Fim' esperado", tk);
            }

            else
            {
                throw Error("'Senão' esperado", tk);
            }
        }
    }
    else if (tk.categ == 'Para')
    {
        tk.next();
        fAtr();
        if (tk.categ == 'Até')
        {
            tk.next();
            fEa();
            if (tk.categ == 'Repita')
            {
                tk.next();
                fLSent();
                if (tk.categ == 'Fim')
                {
                    tk.next();
                    return;
                }
                else
                    throw Error("'Fim' esperado", tk);
            }
            else
                throw Error("'Repita' esperado", tk);
        }
        else
            throw Error("'Até' esperado", tk);
    }
    else
    {
        fAtr();
        return;
    }
}

void fEb() {}

void fAtr() {}

void fEa() {}