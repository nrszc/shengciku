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

//编辑密码为123
void CJ();   //创建生词库
void CE();   //创建汉英单词
void EC();   //创建英汉单词
void XS();   //显示词库
void XSA();  //显示所有单词
void XSCE(); //显示汉英单词
void XSEC(); //显示英汉单词
void BJ();   //编辑词库
void CZ();   //查找生词
void SC();   //删除生词
void XG();   //修改生词
void SCEC(); //删除英汉单词
void SCCE(); //删除汉英单词
void XGEC(); //修改英汉单词
void XGCE(); //修改汉英单词
void CZCE(); //查找汉英单词
void CZEC(); //查找英汉单词
void CX();   //创新功能单词听写

int main()
{
    int Count,choice;
    do{
        printf("\t--------------------------------------------");
        printf("\n\t--------------------------------------------");
        printf("\n\t请输入选项编号(0~5):");
        printf("\n\t1——创建生词库");
        printf("\n\t2——显示词库");
        printf("\n\t3——编辑词库");
        printf("\n\t4——查找生词");
        printf("\n\t5——创新功能");
        printf("\n\t0——退出系统\n");
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


    void CJ() //创建生词库
    {
        FILE *fp;
        char hh;
        printf("请输入创建/添加类型（C为汉英，E为英汉）:");
        getchar();
        scanf("%c",&hh);
        switch(hh)
        {
            case 'E':EC(); break;
            case 'C':CE(); break;
        }
    }


    void CE() //创建汉英单词
    {
        FILE *fp;
        int i=0;
        char a;
        struct Chinese t[MaxSize];
        printf("请输入中文单词:");
        scanf("%s",t[i].word);
        printf("请输入英文单词:");
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
            printf("是否要继续(Y/N):");
            scanf("%c",&a);
            if(a=='N')
                break;
            printf("请输入中文单词:");
            scanf("%s",t[i].word);
            printf("请输入英文单词:");
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



    void EC() //创建英汉单词
    {
        FILE *fp;
        char a;
        int i=0;
        struct English s[MaxSize];
        printf("请输入英文单词:");
        scanf("%s",s[i].word );
        printf("请输入中文单词:");
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
            printf("是否要继续(Y/N):");
            scanf("%c",&a);
            if(a=='N')
                break;
            printf("请输入英文单词:");
            scanf("%s",s[i].word );
            printf("请输入中文单词:");
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



    void XS()  //显示词库
    {
        int a;
        do{
        printf("\n\t------------------------------------");
        printf("\n\t------------------------------------");
        printf("\n\t请输入选项编号(0 ~4):");
        printf("\n\t1——显示所有单词");
        printf("\n\t2——显示中文单词");
        printf("\n\t3——显示英文单词");
        printf("\n\t4——返回");
        printf("\n\t0——退出系统");
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


    void XSA() //显示所有单词
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
            printf("单词:%s    解释:%s\n",t[i].word,t[i].explain);
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
            printf("单词:%s    解释:%s\n",s[i].word,s[i].explain);
        }
        if(fclose(fp1))
        {
            printf("Can not close the file\n");
            return;
        }
        printf("所有单词数为:%d\n",k+n);
    }


    void XSCE() //显示汉英单词
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
            printf("没有汉英单词\n");
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
        for(i=0;i<k;i++)
            printf("单词:%s    解释:%s\n",t[i].word,t[i].explain);
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
        printf("汉英单词数为:%d\n",k);
    }



    void XSEC() //显示英汉单词
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
            printf("没有英汉单词\n");
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
            printf("单词:%s   解释:%s\n",s[i].word,s[i].explain);
        }
        if(fclose(fp))
        {
            printf("Can not close the file\n");
            return;
        }
        printf("英汉单词数为:%d\n",k);
    }



         void BJ() //编辑词库
         {
             int a;
             char c,b[30],d[4]="123";  /*密码为123*/
             getchar();
             printf("请输入密码:");
             scanf("%s",b);
             if(strcmp(b,d)!=0)
             {
                 while(1){
                        printf("密码错误!\n");
                    getchar();
                 printf("是否要重新输入密码（Y/N）:");
                 scanf("%c",&c);
                 if(c!='N'){
                     printf("请输入密码:");
                     scanf("%s",b);
                     if(strcmp(b,d)==0)
                        break;
                            }
                 else
                    return;
                }
             }
        printf("恭喜密码正确!\n");
        getchar();
             do{
        printf("\n\t------------------------------------");
        printf("\n\t------------------------------------");
        printf("\n\t请输入选项编号(0 ~4):");
        printf("\n\t1——添加新词");
        printf("\n\t2——删除旧词");
        printf("\n\t3——修改旧词");
        printf("\n\t4——返回");
        printf("\n\t0——退出系统");
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


         void SC()  //删除生词
         {
             char a;
             printf("请输入删除类型（C为汉英，E为英汉）:");
             getchar();
             scanf("%c",&a);
             switch(a)
             {
                case 'E':SCEC(); break;
                case 'C':SCCE(); break;
             }
         }

         void SCCE() //删除汉英单词
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
            printf("没有汉英数据\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
             do{
             printf("请输入中文单词:");
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(t[i].word,a)==0)
                    break;
                    if(i==k){
                        printf("此单词不在生词库内\n");
                        getchar();}
                    else
                    {
                    for(j=i;j<k-1;j++)
                       t[j]=t[j+1];
                       k--;
                       printf("删除成功\n");
                       getchar();
                    }
                    printf("是否要继续删除（Y/N）:");
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



         void SCEC() //删除英汉单词
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
            printf("没有英汉数据\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;}
            fclose(fp);
             do{
             printf("请输入英文单词:");
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(s[i].word,a)==0)
                    break;
                    if(i==k){
                        printf("此单词不在生词库内\n");
                        getchar();}
                    else
                    {
                        for(j=i;j<k-1;j++)
                            s[j]=s[j+1];
                            k--;
                            printf("删除成功\n");
                            getchar();
                    }
                    printf("是否要继续删除（Y/N）:");
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



         void XG() //修改生词
         {
             char a;
             printf("请输入修改类型（C为汉英，E为英汉）:");
             getchar();
             scanf("%c",&a);
             switch(a)
             {
                case 'E':XGEC(); break;
                case 'C':XGCE(); break;
             }
         }

         void XGCE() //修改汉英单词
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
            printf("没有汉英数据\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
            fclose(fp);
             do{
             printf("请输入中文单词:");
             getchar();
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(t[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("此单词不在生词库内\n");
                    else
                    {
                        printf("请输入修改后的英文解释:");
                        scanf("%s",t[i].explain);
                        printf("修改成功\n");
                    }
                    printf("是否要继续修改（Y/N）:");
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


          void XGEC()  //修改英汉单词
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
            printf("没有英汉数据\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;}
            fclose(fp);
             do{
             printf("请输入英文单词:");
             getchar();
             scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(s[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("此单词不在生词库内\n");
                    else
                        {
                            printf("请输入修改后的中文解释:");

                            scanf("%s",s[i].explain);
                            printf("修改成功\n");
                        }
                    printf("是否要继续修改（Y/N）:");
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


         void CZ() //查找生词
         {
             char a;
             printf("请输入寻找类型（C为汉英，E为英汉）\n");
             getchar();
             scanf("%c",&a);
             switch(a)
             {
                case 'E':CZEC(); break;
                case 'C':CZCE(); break;
             }
         }


         void CZCE() //查找汉英单词
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
            printf("没有汉英数据\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[k].word,t[k].explain);
            k++;}
            fclose(fp);
            do{
            printf("请输入中文单词:");
            scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(t[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("此单词不在生词库内\n");
                    else
                        printf("中文:%s    解释:%s\n",t[i].word,t[i].explain);
                    printf("是否要继续查找（Y/N）:");
                    getchar();
                    scanf("%c",&b);}
            while(b!='N');
         }


         void CZEC() //查找英汉单词
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
            printf("没有英汉数据\n");
            fclose(fp);
            return;
        }
        while(!feof(fp)){
            fscanf(fp,"%10s%10s",s[k].word,s[k].explain);
            k++;}
            fclose(fp);
            do{
            printf("请输入英文单词:");
            scanf("%s",a);
            for(i=0;i<k;i++)
                if(strcmp(s[i].word,a)==0)
                    break;
                    if(i==k)
                        printf("此单词不在生词库内\n");
                    else
                        printf("英文:%s    解释:%s\n",s[i].word,s[i].explain);
                    printf("是否要继续查找（Y/N）:");
                    getchar();
                    scanf("%c",&b);}
            while(b!='N');
         }


         void CX()  //创新功能听写功能
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
            printf("没有汉英数据\n");
            fclose(fp);
            return;
        }
         while(!feof(fp)){
            fscanf(fp,"%10s%10s",t[n].word,t[n].explain);
            n++;}
            fclose(fp);
            printf("显示汉语意思，写出正确的英文单词!\n");
            getchar();
            i=0;
            do{
                k=0;j=0;
            do{
            printf("中文意思:%s\n",t[i].word);
            printf("请输入正确的英文单词:");
            scanf("%s",word);
            if(strcmp(t[i].explain,word)==0)
            {
                printf("恭喜答对了\n");
                k=1;
            }
            else
            {
                printf("请重新输入单词\n");
                j++;
            }
            if(j==3)
            {
                printf("您已经输入错误了3次\n");
            }
            }while(j<3&&k==0);
            i++;
            if(i>=n)
            {
               printf("全部听写完毕\n");
               return;
            }
            printf("要继续选择听写单词吗（Y/N):");
            getchar();
            scanf("%c",&c);
            while(c!='Y'&&c!='N')
            {
        	    printf("请重新输入:");
    	        getchar();
			    scanf("%c",&c);
            };
            }while(c=='Y');
         }


