#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MaxSize 200
struct Chinese{
     char word[25];
     char explain[30];
     };
struct English{
    char word[25];
    char explain[30];
};

//�༭����Ϊ123
void CJ();   //�������ʿ�
void CE();   //������Ӣ����
void EC();   //����Ӣ������
void XS();   //��ʾ�ʿ�
void XSA();  //��ʾ���е���
void XSCE(); //��ʾ��Ӣ����
void XSEC(); //��ʾӢ������
void BJ();   //�༭�ʿ�
void CZ();   //��������
void SC();   //ɾ������
void XG();   //�޸�����
void SCEC(); //ɾ��Ӣ������
void SCCE(); //ɾ����Ӣ����
void XGEC(); //�޸�Ӣ������
void XGCE(); //�޸ĺ�Ӣ����
void CZCE(); //���Һ�Ӣ����
void CZEC(); //����Ӣ������
void CX();   //���¹��ܵ�����д

int main()
{
    int Count,choice;
    do{
        printf("\t--------------------------------------------");
        printf("\n\t--------------------------------------------");
        printf("\n\t������ѡ����(0~5):");
        printf("\n\t1�����������ʿ�");
        printf("\n\t2������ʾ�ʿ�");
        printf("\n\t3�����༭�ʿ�");
        printf("\n\t4������������");
        printf("\n\t5�������¹���");
        printf("\n\t0�����˳�ϵͳ\n");
        printf("\t--------------------------------------------");
        printf("\n\t--------------------------------------------\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:CJ(); break;
        case 2:XS(); break;
        case 3:BJ(); break;
        case 4:CZ(); break;
        case 5:CX(); break;
        case 0:break;
    }
    }while(choice!=0);
    printf("END\n");
}


    void CJ() //�������ʿ�
    {
        FILE *fp;
        char hh;
        printf("�����봴��/������ͣ�CΪ��Ӣ��EΪӢ����:");
        getchar();
        scanf("%c",&hh);
        switch(hh)
        {
            case 'E':EC(); break;
            case 'C':CE(); break;
        }
    }


    void CE() //������Ӣ����
    {
        FILE *fp;
        int i=0;
        char a;
        struct Chinese t[MaxSize];
        printf("���������ĵ���:");
        scanf("%s",t[i].word);
        printf("������Ӣ�ĵ���:");
        scanf("%s",t[i].explain);
        getchar();
        if((fp=fopen("c:\\123.txt","a"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        fprintf(fp,"%10s%10s",t[i].word,t[i].explain);
        i++;
        while(1)
        {
            printf("�Ƿ�Ҫ����(Y/N):");
            scanf("%c",&a);
            if(a=='N')
                break;
            printf("���������ĵ���:");
            scanf("%s",t[i].word);
            printf("������Ӣ�ĵ���:");
            scanf("%s",t[i].explain);
            getchar();
            fprintf(fp,"%10s%10s",t[i].word,t[i].explain);
            i++;
        }
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
    }



    void EC() //����Ӣ������
    {
        FILE *fp;
        char a;
        int i=0;
        struct English s[MaxSize];
        printf("������Ӣ�ĵ���:");
        scanf("%s",s[i].word );
        printf("���������ĵ���:");
        scanf("%s",s[i].explain );
        if((fp=fopen("c:\\abc.txt","a"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        fprintf(fp,"%10s%10s",s[i].word,s[i].explain);
        i++;
        while(1)
        {
            getchar();
            printf("�Ƿ�Ҫ����(Y/N):");
            scanf("%c",&a);
            if(a=='N')
                break;
            printf("������Ӣ�ĵ���:");
            scanf("%s",s[i].word );
            printf("���������ĵ���:");
            scanf("%s",s[i].explain );
            fprintf(fp,"%10s%10s",s[i].word,s
                    [i].explain);
            i++;
        }
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
    }



    void XS()  //��ʾ�ʿ�
    {
        int a;
        do{
        printf("\n\t------------------------------------");
        printf("\n\t------------------------------------");
        printf("\n\t������ѡ����(0 ~4):");
        printf("\n\t1������ʾ���е���");
        printf("\n\t2������ʾ���ĵ���");
        printf("\n\t3������ʾӢ�ĵ���");
        printf("\n\t4��������");
        printf("\n\t0�����˳�ϵͳ");
        printf("\n\t------------------------------------");
        printf("\n\t------------------------------------\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:XSA();break;
            case 2:XSCE();break;
            case 3:XSEC();break;
            case 4:return;
            case 0:exit(0);
        }

        }
        while(a!=0);
    }


    void XSA() //��ʾ���е���
    {
        FILE *fp,*fp1;
        struct Chinese t[MaxSize];
        struct English s[MaxSize],s1;
        int j=0,i,n,k=0,m;
        char c,b;
        if((fp=fopen("c:\\123.txt","a+"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
            k=0;
        while(!feof(fp)){
                fscanf(fp,"%10s%10s",t[k].word,t[k].explain);

        k++;}
        for(i=0;i<k;i++)
            printf("����:%s    ����:%s\n",t[i].word,t[i].explain);
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
        n=k;
        k=0;
        if((fp1=fopen("c:\\abc.txt","a+"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp1))==EOF)
            k=0;
        while(!feof(fp1))
        {
            fscanf(fp1,"%10s%10s",s[k].word,s[k].explain);
            k++;
        }
        for(i=1;i<k;i++)
            for(j=0;j<k-i;j++)
            if(strcmp(s[j].word,s[j+1].word)>0)
        {
            s1=s[j];
            s[j]=s[j+1];
            s[j+1]=s1;
        }
        for(i=0;i<k;i++)
        {
            printf("����:%s    ����:%s\n",s[i].word,s[i].explain);
        }
        if(fclose(fp1))
        {
            printf("Can not close the file\n");
            return;
        }
        printf("���е�����Ϊ:%d\n",k+n);
    }


    void XSCE() //��ʾ��Ӣ����
    {
        FILE *fp;
        int i,k=0;
        char c;
        struct Chinese t[MaxSize];
        if((fp=fopen("c:\\123.txt","a+"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û�к�Ӣ����\n");
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
        for(i=0;i<k;i++)
            printf("����:%s    ����:%s\n",t[i].word,t[i].explain);
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
        printf("��Ӣ������Ϊ:%d\n",k);
    }



    void XSEC() //��ʾӢ������
    {
        struct English s[MaxSize],s1;
        FILE *fp;
        int i,j,k=0;
        char c;
        if((fp=fopen("c:\\abc.txt","a+"))==NULL)
        {
           printf("File open error\n");
           return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û��Ӣ������\n");
            return;
        }
        while(!feof(fp))
        {
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;
        }
        for(i=1;i<k;i++)
            for(j=0;j<k-i;j++)
            if(strcmp(s[j].word,s[j+1].word)>0)
        {
            s1=s[j];
            s[j]=s[j+1];
            s[j+1]=s1;
        }
        for(i=0;i<k;i++)
        {
            printf("����:%s   ����:%s\n",s[i].word,s[i].explain);
        }
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
        printf("Ӣ��������Ϊ:%d\n",k);
    }



         void BJ() //�༭�ʿ�
         {
             int a;
             char c,b[30],d[4]="123";  /*����Ϊ123*/
             getchar();
             printf("����������:");
             scanf("%s",b);
             if(strcmp(b,d)!=0)
             {
                 while(1){
                        printf("�������!\n");
                    getchar();
                 printf("�Ƿ�Ҫ�����������루Y/N��:");
                 scanf("%c",&c);
                 if(c!='N'){
                     printf("����������:");
                     scanf("%s",b);
                     if(strcmp(b,d)==0)
                        break;
                            }
                 else
                    return;
                }
             }
        printf("��ϲ������ȷ!\n");
        getchar();
             do{
        printf("\n\t------------------------------------");
        printf("\n\t------------------------------------");
        printf("\n\t������ѡ����(0 ~4):");
        printf("\n\t1��������´�");
        printf("\n\t2����ɾ���ɴ�");
        printf("\n\t3�����޸ľɴ�");
        printf("\n\t4��������");
        printf("\n\t0�����˳�ϵͳ");
        printf("\n\t------------------------------------");
        printf("\n\t------------------------------------\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:CJ();break;
            case 2:SC();break;
            case 3:XG();break;
            case 4:return;
            case 0:exit(0);
        }}
        while(a!=0);
         }


         void SC()  //ɾ������
         {
             char a;
             printf("������ɾ�����ͣ�CΪ��Ӣ��EΪӢ����:");
             getchar();
             scanf("%c",&a);
             switch(a)
             {
                case 'E':SCEC(); break;
                case 'C':SCCE(); break;
             }
         }

         void SCCE() //ɾ����Ӣ����
         {
             FILE *fp;
             int k=0,i,j,n=0;
             char a[30],b,c;
             struct Chinese t[MaxSize];
             if((fp=fopen("c:\\123.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û�к�Ӣ����\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
             do{
             printf("���������ĵ���:");
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(t[i].word,a)==0)
                    break;
                    if(i==k){
                        printf("�˵��ʲ������ʿ���\n");
                        getchar();}
                    else
                    {
                    for(j=i;j<k-1;j++)
                       t[j]=t[j+1];
                       k--;
                       printf("ɾ���ɹ�\n");
                       getchar();
                    }
                    printf("�Ƿ�Ҫ����ɾ����Y/N��:");
                    scanf("%c",&b);}
            while(b!='N');
            fclose(fp);
            if((fp=fopen("c:\\123.txt","w"))==NULL)
          {
            printf("File open error\n");
            return;
          }
          for(i=0;i<k;i++)
              fprintf(fp,"%10s%10s",t[i].word,t[i].explain);
              fclose(fp);
         }



         void SCEC() //ɾ��Ӣ������
         {
             FILE *fp;
             int k=0,i,j,n=0;
             char a[30],b,c;
             struct English s[MaxSize];
             if((fp=fopen("c:\\abc.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û��Ӣ������\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;}
            fclose(fp);
             do{
             printf("������Ӣ�ĵ���:");
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(s[i].word,a)==0)
                    break;
                    if(i==k){
                        printf("�˵��ʲ������ʿ���\n");
                        getchar();}
                    else
                    {
                        for(j=i;j<k-1;j++)
                            s[j]=s[j+1];
                            k--;
                            printf("ɾ���ɹ�\n");
                            getchar();
                    }
                    printf("�Ƿ�Ҫ����ɾ����Y/N��:");
                    scanf("%c",&b);}
            while(b!='N');
            if((fp=fopen("c:\\abc.txt","w"))==NULL)
          {
            printf("File open error\n");
            return;
          }
          for(i=0;i<k;i++)
              fprintf(fp,"%10s%10s",s[i].word,s[i].explain);
              fclose(fp);
         }



         void XG() //�޸�����
         {
             char a;
             printf("�������޸����ͣ�CΪ��Ӣ��EΪӢ����:");
             getchar();
             scanf("%c",&a);
             switch(a)
             {
                case 'E':XGEC(); break;
                case 'C':XGCE(); break;
             }
         }

         void XGCE() //�޸ĺ�Ӣ����
         {
             FILE *fp;
             int k=0,i,j;
             char a[30],b,c;
             struct Chinese t[MaxSize];
             if((fp=fopen("c:\\123.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û�к�Ӣ����\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
            fclose(fp);
             do{
             printf("���������ĵ���:");
             getchar();
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(t[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("�˵��ʲ������ʿ���\n");
                    else
                    {
                        printf("�������޸ĺ��Ӣ�Ľ���:");
                        scanf("%s",t[i].explain);
                        printf("�޸ĳɹ�\n");
                    }
                    printf("�Ƿ�Ҫ�����޸ģ�Y/N��:");
                    getchar();
                    scanf("%c",&b);}
            while(b!='N');
            if((fp=fopen("c:\\123.txt","w"))==NULL)
          {
            printf("File open error\n");
            return;
          }
          for(i=0;i<k;i++)
              fprintf(fp,"%10s%10s",t[i].word,t[i].explain);
              fclose(fp);
         }


          void XGEC()  //�޸�Ӣ������
         {
             FILE *fp;
             int k=0,i,j;
             char a[30],b,c;
             struct English s[MaxSize];
             if((fp=fopen("c:\\abc.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û��Ӣ������\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;}
            fclose(fp);
             do{
             printf("������Ӣ�ĵ���:");
             getchar();
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(s[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("�˵��ʲ������ʿ���\n");
                    else
                        {
                            printf("�������޸ĺ�����Ľ���:");

                            scanf("%s",s[i].explain);
                            printf("�޸ĳɹ�\n");
                        }
                    printf("�Ƿ�Ҫ�����޸ģ�Y/N��:");
                    getchar();
                    scanf("%c",&b);}
            while(b!='N');
            if((fp=fopen("c:\\abc.txt","w"))==NULL)
          {
            printf("File open error\n");
            return;
          }
          for(i=0;i<k;i++)
              fprintf(fp,"%10s%10s",s[i].word,s[i].explain);
              fclose(fp);
         }


         void CZ() //��������
         {
             char a;
             printf("������Ѱ�����ͣ�CΪ��Ӣ��EΪӢ����\n");
             getchar();
             scanf("%c",&a);
             switch(a)
             {
                case 'E':CZEC(); break;
                case 'C':CZCE(); break;
             }
         }


         void CZCE() //���Һ�Ӣ����
         {
             FILE *fp;
             int k=0,i,j;
             char a[30],b,c;
             struct Chinese t[MaxSize];
             if((fp=fopen("c:\\123.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û�к�Ӣ����\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
            fclose(fp);
            do{
            printf("���������ĵ���:");
            scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(t[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("�˵��ʲ������ʿ���\n");
                    else
                        printf("����:%s    ����:%s\n",t[i].word,t[i].explain);
                    printf("�Ƿ�Ҫ�������ң�Y/N��:");
                    getchar();
                    scanf("%c",&b);}
            while(b!='N');
         }


         void CZEC() //����Ӣ������
         {
             FILE *fp;
             int k=0,i,j;
             char a[30],b,c;
             struct English s[MaxSize];
             if((fp=fopen("c:\\abc.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û��Ӣ������\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;}
            fclose(fp);
            do{
            printf("������Ӣ�ĵ���:");
            scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(s[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("�˵��ʲ������ʿ���\n");
                    else
                        printf("Ӣ��:%s    ����:%s\n",s[i].word,s[i].explain);
                    printf("�Ƿ�Ҫ�������ң�Y/N��:");
                    getchar();
                    scanf("%c",&b);}
            while(b!='N');
         }


         void CX()  //���¹�����д����
         {
             FILE *fp,*fp1;
             int k,i,j=0,n=0;
             char a[30],word[30],c;
             struct Chinese t[MaxSize];
             if((fp=fopen("c:\\123.txt","r"))==NULL)
        {
            printf("File open error\n");
            return;
        }
        if((c=fgetc(fp))==EOF)
        {
            printf("û�к�Ӣ����\n");
            fclose(fp);
            return;
        }
         while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[n].word,t[n].explain);
            n++;}
            fclose(fp);
            printf("��ʾ������˼��д����ȷ��Ӣ�ĵ���!\n");
            getchar();
            i=0;
            do{
                k=0;j=0;
            do{
            printf("������˼:%s\n",t[i].word);
            printf("��������ȷ��Ӣ�ĵ���:");
            scanf("%s",word);
            if(strcmp(t[i].explain,word)==0)
            {
                printf("��ϲ�����\n");
                k=1;
            }
            else
            {
                printf("���������뵥��\n");
                j++;
            }
            if(j==3)
            {
                printf("���Ѿ����������3��\n");
            }
            }while(j<3&&k==0);
            i++;
            if(i>=n)
            {
               printf("ȫ����д���\n");
               return;
            }
            printf("Ҫ����ѡ����д������Y/N):");
            getchar();
            scanf("%c",&c);
            while(c!='Y'&&c!='N')
            {
        	    printf("����������:");
    	        getchar();
			    scanf("%c",&c);
            };
            }while(c=='Y');
         }


