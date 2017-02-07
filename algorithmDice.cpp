#include <iostream>

using namespace std;

main()
{
	// Var


	// Valor de Aposta Inicial - VAI
	double vai = 0; 
	//Banca
	double banca = 0;
	// vetor Rodada
	double rodada[1000];



	//Entrada
	cout<<"** Algorithm Dice **"<<endl<<endl;
	cout<<"[DIGITE]"<<endl;

	cout<<"- Aposta inicial: ";
	cin>>vai;

	cout<<"- Banca: ";
	cin>>banca;
	cout<<endl;

	//processamento 1
	// var processamento 1
	int i = 0,total_apostas_rodada = 0;
	double aux = 0;

	aux = vai;
	for (i = 0; aux <= banca/2; i++)
	{
		cout.precision(8);
		cout<<i+1<<" - "<<fixed<<aux<<endl;
		rodada[i] = aux;
		aux *= 2;
	}
	total_apostas_rodada = i;

	cout<<"--- Cada rodada possui "<<total_apostas_rodada<<" APOSTAS"<<endl<<endl;


	//programa 2

	//var
	double lucro_es = 0, res = 0;
	// Razão da prograssão geométrica
	double q = 0;

	//Entrada
	cout<<" 	** VAMOS APOSTAR ** "<<endl<<endl;
	cout<<"-- Lucro Esperado: ";
	cin>>lucro_es;

	cout<<"-- Razão do tempo de espera[min]: ";
	cin>>q;

	//processamento 1
	//var
	int total_rodadas = lucro_es/vai, y = 0;
	//PG tempo
	double tem_esp = 0;
	// aposta, 1 - ganhou, 0 - perdeu;
	bool aposta = 0,est = 0;

	cout<<endl<<"--- Para alcançar esse lucro você deve ganhar: "<<total_rodadas<<" RODADAS"<<endl<<endl;
	cout<<"-- Apartir de agora digite de acordo com o resultado da aposta: "<<endl<<" [1] - Ganhou"<<endl<<" [0] - Perdeu"<<endl;

	for (i = 0; i < total_rodadas && est == 0; ++i)
	{
		cout<<"[Rodada - "<<i+1<<" ] - Apostar: "<<rodada[y]<<endl;
		cin>>aposta;

		while(aposta==0 && est == 0)
		{
			res -= rodada[y];


			y++;
			tem_esp += q;

			if (y < total_apostas_rodada)
			{	
							
				cout<<"[Rodada - "<<i+1<<" ] - Apostar: "<<rodada[y]<<" - em "<<tem_esp<<" min"<<endl;
				cin>>aposta;
			}
			else
			{
				est = 1;
				break;				
			}
			
		}


		res = est != 0 ? res:res + rodada[y];
		tem_esp = 0;
		y = 0;
	}

	if (est)
	{
		cout<<" ** Você está sem sorte **"<<endl;
		cout<<" PREJUÍZO: "<<res<<endl;
		cout<<" TOTAL: "<<banca<<" - "<<-res<<" = "<<banca+res<<endl;
	}
	else
	{
		cout<<endl<<" *** Parabéns ***"<<endl;
		cout<<" LUCRO: "<<res<<endl;
		cout<<" TOTAL: "<<banca<<" + "<<res<<" = "<<banca+res<<endl;
	}
}