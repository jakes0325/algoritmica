cout<<"desea continuar con el programa?(si o no) :";
		fflush(stdin);
		do{
			getline(cin,op);
			for(int c=0;c<op.length();c++){
				op[c]=toupper(op[c]);
			}
			sw=0;
			for(int c=0;(c<op.length())&&(sw==0);c++){
				if(isdigit(op[c])==true){
					cout<<"usted ingreso un nro, por favor ingrese lo indicado";
					cin.clear();
					fflush(stdin);
					cout<<endl<<" ingrese de nuevo: ";
					sw=1;
				}else if((op!="SI")||(op!="NO")){
					cout<<"ERROR ingrese (si o no):";
					sw=1;
				}
			}	
		}while(sw==1);
