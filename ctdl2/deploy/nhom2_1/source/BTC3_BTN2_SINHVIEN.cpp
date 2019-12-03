//CAY NHI PHAN LUU TRU SINH VIEN
#include<stdio.h>
#include<String.h>
struct SinhVien
{
	char masv[5], ten[20],lop[7];
	float dtb;
	SinhVien *Adr_TrL_T2, *Adr_TrR_T2;
};
//Them phan tu vao cay nhi phan
SinhVien *Add_Node_T2(SinhVien *Tr, SinhVien *p)
{
	SinhVien *tmp,*TMP;
	if(Tr==NULL)
		Tr=p;
	else
	{
		tmp=Tr;
		while(tmp!=NULL)
		{
			TMP=tmp;
			if(tmp->dtb > p->dtb)
				tmp=tmp->Adr_TrL_T2;
			else
				tmp=tmp->Adr_TrR_T2;
		}
		if(TMP->dtb > p->dtb)
			TMP->Adr_TrL_T2=p;
		else
			TMP->Adr_TrR_T2=p;
	}
	return Tr;
}
//Tao cay nhi phan tim kiem
SinhVien *IP(SinhVien *Tr)
{
	int i=1;
	SinhVien *p;
	Tr=NULL;
	do
	{
		fflush(stdin);
		p= new SinhVien;
		printf("Nhap thong tin SV %d: ",i);
		printf("\nMa SV: ");
		gets(p->masv);
		if(strcmp(p->masv,"0")!=0)
		{
		printf("Ten SV: ");
		gets(p->ten);
		printf("Lop: ");
		gets(p->lop);
		printf("DTB: ");
		scanf("%f",&p->dtb);
		p->Adr_TrL_T2=NULL;
		p->Adr_TrR_T2=NULL;
		Tr=Add_Node_T2(Tr,p);
		i++;
		}
	}
	while(strcmp(p->masv,"0")!=0);
	return Tr;
}
//In cac phan tu theo thu tu trai - goc - phai
SinhVien OP_TGP(SinhVien *Tr)
{
	if(Tr != NULL)
	{
		OP_TGP(Tr->Adr_TrL_T2);
		printf("\n%5s |%20s |%7s |%2.2f",Tr->masv,Tr->ten,Tr->lop,Tr->dtb);
		OP_TGP(Tr->Adr_TrR_T2);
	}
}
//Bo sung SV vao cay nhi phan tim kiem
SinhVien *Add(SinhVien *Tr)
{
	SinhVien *p;
	int n;
	do
	{
		p = new SinhVien;
		fflush(stdin);
		printf("Nhap thong tin cua SV can them vao");
		printf("\nMa SV: ");
		gets(p->masv);
		printf("Ten SV: ");
		gets(p->ten);
		printf("Lop: ");
		gets(p->lop);
		printf("DTB: ");
		scanf("%f",&p->dtb);
		p->Adr_TrL_T2=NULL;
		p->Adr_TrR_T2=NULL;
		Tr=Add_Node_T2(Tr,p);
		printf("Ban co muon them nua khong? 1-Co, 0-Khong: ");
		scanf("%d",&n);
	}while(n!=0);
	return Tr;
}
//Dem trong cay co bn SV co DTB > 5.5
int C_DTB(SinhVien *Tr)
{
	if(Tr== NULL)
		return 0;
	if(Tr->dtb > 5.5)
		return 1+C_DTB(Tr->Adr_TrR_T2);
	else
		return C_DTB(Tr->Adr_TrR_T2)+C_DTB(Tr->Adr_TrL_T2);
}
//In SV co DTB > 5.5
SinhVien OP_TGP_DTB(SinhVien *Tr)
{
	if(Tr != NULL)
	{
		OP_TGP_DTB(Tr->Adr_TrL_T2);
		if(Tr->dtb > 5.5)
			printf("\n%5s |%10s |%7s |%2.2f",Tr->masv,Tr->ten,Tr->lop,Tr->dtb);
		OP_TGP_DTB(Tr->Adr_TrR_T2);
	}
}
//Tim kiem
SinhVien *Search(SinhVien *Tr)
{	
	SinhVien *tmp;
	if(Tr==NULL)
		return NULL;
	else
	{
		tmp=Tr;
		while(tmp!=NULL && tmp->dtb>=5.5)
			if(tmp->dtb >= 5.5)
				tmp=tmp->Adr_TrL_T2;
			else
				tmp=tmp->Adr_TrR_T2;
		if(tmp!=NULL)
			return tmp;
		else
			return NULL;
	}
}
//Node can xoa la nut Goc
SinhVien *Delete_G(SinhVien *Tr)
{
	SinhVien *tmp, *R;
	tmp=Tr;
	if(tmp->Adr_TrL_T2!=NULL)
	{
		R=Tr->Adr_TrR_T2;
		Tr=Tr->Adr_TrL_T2;
		tmp->Adr_TrL_T2=NULL;
		tmp->Adr_TrR_T2=NULL;
		tmp=Tr;
		while(tmp->Adr_TrR_T2!=NULL)
			tmp=tmp->Adr_TrR_T2;
		tmp->Adr_TrR_T2=R;
	}
	else
	{
		Tr=Tr->Adr_TrR_T2;
		tmp->Adr_TrR_T2=NULL;
	}
	return Tr;
}
//Node can xoa la nut La
SinhVien *Delete_L(SinhVien *Tr,SinhVien *inf)
{
	if(Tr->Adr_TrR_T2==inf)
		Tr->Adr_TrR_T2=NULL;
	else
		Tr->Adr_TrL_T2=NULL;
	return Tr;
}
//Node can xoa khong co cay con ben trai
SinhVien *Delete_NoTrL(SinhVien *Tr,SinhVien *inf)
{
	SinhVien *R;
	R=inf->Adr_TrR_T2;
	if(Tr->Adr_TrL_T2==inf)
		Tr->Adr_TrL_T2=R;
	else
		Tr->Adr_TrR_T2=R;
	inf->Adr_TrR_T2=NULL;
	return Tr;				
}
//Node can xoa khong có cay con ben Phai
SinhVien *Delete_NoTrR(SinhVien *Tr,SinhVien *inf)
{
	SinhVien *L;
	L=inf->Adr_TrL_T2;
	if(Tr->Adr_TrL_T2 == inf)
		Tr->Adr_TrL_T2=L;
	else
		Tr->Adr_TrR_T2=L;
	inf->Adr_TrL_T2=NULL;
	return Tr;
}
//Node can xoa có ca cay con ben trai va ben phai
SinhVien *Delete_TrR_TrL(SinhVien *Tr,SinhVien *inf)
{
	if(Tr->Adr_TrL_T2==inf)
	{
		Tr->Adr_TrL_T2=inf->Adr_TrL_T2;
		Tr=Tr->Adr_TrL_T2;
	}
	else
	{
		Tr->Adr_TrR_T2=inf->Adr_TrL_T2;
		Tr=Tr->Adr_TrR_T2;
	}
	while(Tr->Adr_TrR_T2!=NULL)
		Tr=Tr->Adr_TrR_T2;
	Tr->Adr_TrR_T2 = inf->Adr_TrR_T2;
	inf->Adr_TrR_T2=NULL;
	inf->Adr_TrL_T2=NULL;
	return Tr;
}
SinhVien *Delete(SinhVien *Tr)
{	
	SinhVien *tmp, *t;
	while(Search(Tr) != NULL)
	{
		tmp= Search(Tr);
		if(tmp == Tr)
			Tr=Delete_G(Tr);
		else
		{
			t=Tr;
			while(t->Adr_TrR_T2!= tmp && t->Adr_TrL_T2 != tmp)
				if(t->dtb > 5.5)
					t=t->Adr_TrL_T2;
				else
					t=t->Adr_TrR_T2;
			if(tmp->Adr_TrL_T2==NULL && tmp->Adr_TrR_T2==NULL)
				t=Delete_L(t,tmp);
			else
				if(tmp->Adr_TrL_T2==NULL)
					t=Delete_NoTrL(t,tmp);
				else
					if(tmp->Adr_TrR_T2==NULL)
						t=Delete_NoTrR(t,tmp);
					else
						t=Delete_TrR_TrL(t,tmp);
		}
	}
	return Tr;
}
main()
{
	SinhVien *Tree;
	float dtb;
	int chon;
	do
	{
		printf("\n==================\n");
		printf("===    MENU    ===\n");
		printf("|1. Tao danh sach sinh |\n");
		printf("|2. In danh sach sinh vien |\n");
		printf("|3. Bo sung sinh vien vao danh sach |\n");
		printf("|4. So sinh vien trong danh sach co dtb > 5.5 |\n");
		printf("|5. In nhung sinh vien co dtb > 5.5 |\n");
		printf("|6. Xoa nhung sinh vien co dtb < 5.5 |\n");
		printf("|0. Thoat |\n");
		printf("Chon 1 trong cac chuc nang tren: ");
		scanf("%d",&chon);
		switch(chon)
		{
			case 1:
				printf("1.Nhap danh sach sinh vien");
				Tree=IP(Tree);
				break;
			case 2:
				printf("2.In danh sach sinh vien");
				OP_TGP(Tree);
				break;
			case 3:
				printf("3. Them sinh vien vao danh sach");
				Tree=Add(Tree);
				printf("Danh sach sau khi them la: \n");
				OP_TGP(Tree);
				break;
			case 4:
				printf("4. So sinh vien co dtb > 5.5 la: %d",C_DTB(Tree));
				break;
			case 5:
				printf("5. Danh sach sinh vien co dtb > 5.5: \n");
				OP_TGP_DTB(Tree);
				break;
			case 6:
				printf("6. Xoa nhung sinh vien co dtb < 5.5");
				Tree=Delete(Tree);
				OP_TGP(Tree);
				break;
			case 0:
				break;
			default:
				printf("Nhap cac so tu 0 -> 6");
		}
	}while(chon!=0);
}
