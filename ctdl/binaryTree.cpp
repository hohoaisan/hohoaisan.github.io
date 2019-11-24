#include <stdio.h>
#include <string.h>
struct SinhVien
{
    char masv[13], tensv[25], lop[10];
    float dtb;
};
struct Node_BnTr
{
    SinhVien Data;
    Node_BnTr *Adr_TrL, *Adr_TrR;
};

Node_BnTr *Add_Node(Node_BnTr *Tr, Node_BnTr *node)
{
    Node_BnTr *tmp, *TMP;
    if (Tr == NULL)
        Tr = node;
    else
    {
        tmp = Tr;
        while (tmp != NULL)
        {
            TMP = tmp;
            if (tmp->Data.dtb > node->Data.dtb)
                tmp = tmp->Adr_TrL;
            else
                tmp = tmp->Adr_TrR;
        }
        if (TMP->Data.dtb > node->Data.dtb)
            TMP->Adr_TrL = node;
        else
            TMP->Adr_TrR = node;
    }
    return Tr;
}
//in trai-goc-phai
void BRW_NODE(Node_BnTr *Tr)
{
    if (Tr != NULL)
    {
        BRW_NODE(Tr->Adr_TrL);
        printf("%13s | %25s | %10s | %6.2f |\n", Tr->Data.masv, Tr->Data.tensv, Tr->Data.lop, Tr->Data.dtb);
        BRW_NODE(Tr->Adr_TrR);
    }
}

Node_BnTr *Khoitao(Node_BnTr *Tree)
{
    if (Tree == NULL)
    {
        Node_BnTr *p;
        int n;
        do
        {
            printf("Nhap so sinh vien : ");
            scanf("%d", &n);
        } while (n <= 0);
        for (int i = 1; i <= n; i++)
        {
            p = new Node_BnTr;
            p->Adr_TrL = NULL;
            p->Adr_TrR = NULL;
            fflush(stdin);
            printf("Nhap thong tin sv :\n");
            printf("Nhap ma sinh vien     : ");
            gets(p->Data.masv);
            printf("Nhap ho ten sinh vien : ");
            gets(p->Data.tensv);
            printf("Nhap lop cua sinh vien: ");
            gets(p->Data.lop);
            printf("Nhap diem trung binh  : ");
            scanf("%f", &p->Data.dtb);
            Tree = Add_Node(Tree, p);
        }
    }
    else
        printf("Danh sach sinh vien da duoc khoi tao, xin moi bo sung\n");
    return Tree;
}
Node_BnTr *InsertNode(Node_BnTr *Tr)
{
    Node_BnTr *p;
    p = new Node_BnTr;
    fflush(stdin);
    printf("Nhap thong tin sv can bo sung :\n");
    printf("Nhap ma sinh vien     : ");
    gets(p->Data.masv);
    printf("Nhap ho ten sinh vien : ");
    gets(p->Data.tensv);
    printf("Nhap lop cua sinh vien: ");
    gets(p->Data.lop);
    printf("Nhap diem trung binh  : ");
    scanf("%f", &p->Data.dtb);
    p->Adr_TrL = NULL;
    p->Adr_TrR = NULL;
    Tr = Add_Node(Tr, p);
    return Tr;
}

int demtren55(Node_BnTr *Tr)
{

    if (Tr != NULL)
        if (Tr->Data.dtb > 5.5)
            return 1 + demtren55(Tr->Adr_TrL) + demtren55(Tr->Adr_TrR);
        else
            return demtren55(Tr->Adr_TrL) + demtren55(Tr->Adr_TrR);
    else
        return 0;
}
void Outdtb(Node_BnTr *Tr)
{
    if (Tr != NULL)
    {
        if (Tr->Data.dtb > 5.5)
            printf(" %3s || %12s || %5s || %0.2f\n", Tr->Data.masv, Tr->Data.tensv, Tr->Data.lop, Tr->Data.dtb);
        Outdtb(Tr->Adr_TrL);
        Outdtb(Tr->Adr_TrR);
    }
}

Node_BnTr *Search(Node_BnTr *Tr, float info)
{
    Node_BnTr *tmp;
    if (Tr == NULL)
        return NULL;
    else
    {
        if (Tr->Data.dtb < info)
            return Tr;
        else
            return Search(Tr->Adr_TrL, info);
    }
}
Node_BnTr *Delete(Node_BnTr *Tr, float info)
{
    Node_BnTr *tmp, *R, *t, *L;
    while (Search(Tr, info) != NULL)
    {
        tmp = Search(Tr, info);
        if (Tr == tmp)
        {
            if (tmp->Adr_TrL != NULL)
            {
                R = Tr->Adr_TrR;
                Tr = Tr->Adr_TrL;
                tmp->Adr_TrL = NULL;
                tmp->Adr_TrR = NULL;
                tmp = Tr;
                while (tmp->Adr_TrR != NULL)
                    tmp = tmp->Adr_TrR;
                tmp->Adr_TrR = R;
            }
            else
            {
                Tr = Tr->Adr_TrR;
                tmp->Adr_TrR = NULL;
            }
        }
        else
        {
            t = Tr;
            while (t->Adr_TrR != tmp && t->Adr_TrL != tmp)
            {
                if (t->Data.dtb > info)
                    t = t->Adr_TrL;
                else
                    t = t->Adr_TrR;
            }
            if (tmp->Adr_TrL == NULL && tmp->Adr_TrR == NULL)
                if (t->Adr_TrR == tmp)
                    t->Adr_TrR = NULL;
                else
                    t->Adr_TrL = NULL;
            else if (tmp->Adr_TrL == NULL)
            {
                R = tmp->Adr_TrR;
                if (t->Adr_TrL == tmp)
                    t->Adr_TrL = R;
                else
                    t->Adr_TrR = R;
                tmp->Adr_TrR = NULL;
            }
            else if (tmp->Adr_TrR == NULL)
            {
                L = tmp->Adr_TrL;
                if (t->Adr_TrL == tmp)
                    t->Adr_TrL = L;
                else
                    t->Adr_TrR = L;
                tmp->Adr_TrL = NULL;
            }
            else
            {
                if (t->Adr_TrL == tmp)
                {
                    t->Adr_TrL = tmp->Adr_TrL;
                    t = t->Adr_TrL;
                }
                else
                {
                    t->Adr_TrR = tmp->Adr_TrL;
                    t = t->Adr_TrR;
                }
                while (t->Adr_TrR != NULL)
                    t = t->Adr_TrR;
                t->Adr_TrR = tmp->Adr_TrR;
                tmp->Adr_TrR = NULL;
                tmp->Adr_TrL = NULL;
            }
        }
    }
    return Tr;
}

int main()
{
    int choice, dung, d;
    Node_BnTr *Tree;
    Tree = NULL;
    while (dung != 1)
    {
        printf("================================\n");
        printf("===============MENU=============\n");
        printf("================================\n");
        printf("1.Nhap sinh vien vao cay T\n");
        printf("2.In cay sinh vien\n");
        printf("3.Bo sung sinh vien\n");
        printf("4.Dem trong cay so sinh vien co diem trung binh tren 5,5\n");
        printf("5.In cay T cac sinh vien co diem trung binh tren 5,5\n");
        printf("6.Xoa cay T cac sinh vien co diem trung binh duoi 5,5\n");
        printf("0.Exits !\n");
        printf("Moi lua chon choice 0--->6 :\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            Tree = Khoitao(Tree);
            printf("Danh sach sinh vien trong cay T sau khi khoi tao la :\n");
            BRW_NODE(Tree);
            printf("\n");
            break;
        case 2:
            printf("Danh sach sinh vien trong cay:\n");
            BRW_NODE(Tree);
            break;
        case 3:
            Tree = InsertNode(Tree);
            printf("Danh sach sinh vien trong cay T sau khi bo sung :\n");
            BRW_NODE(Tree);
            printf("\n");
            break;
        case 4:
            printf("So sinh vien co diem tren 5.5 la %d\n", demtren55(Tree));
            break;
        case 5:
            printf("Danh sach sinh vien co dtb tren 5.5:\n");
            Outdtb(Tree);
            printf("\n");
            break;
        case 6:
            printf("Xoa danh sach sinh vien co dtb duoi 5.5\n");
            Tree = Delete(Tree, 5.5);
            BRW_NODE(Tree);
            printf("\n");
            break;
        case 0:
            dung = 1;
            printf("EXIT !");
            break;
        default:
            printf("Vui long nhap vao cac so tu 1->6: ");
            break;
        }
    }
}
