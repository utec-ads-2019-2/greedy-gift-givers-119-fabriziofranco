#include <iostream>
#include <vector>

using namespace std;

int main(){
    int contralador = 1;
    int n_personas;
    while(cin>>n_personas){
        vector<pair<string,int>> cuentas;

        for(auto i=0;i<n_personas;i++){
            pair<string, int> cuenta;
            cin>>cuenta.first;
            cuenta.second=0;
            cuentas.push_back(cuenta);
        }

        for (int j = 0; j < n_personas; ++j) {
            string persona; int dinero=0,numero_de_regalos=0,cantidad_por_persona=0;
            cin>>persona>>dinero>>numero_de_regalos;
            if(dinero!=0 && numero_de_regalos!=0)
                cantidad_por_persona=dinero/numero_de_regalos;
            for(int i=0;i<n_personas;i++){
                if(cuentas[i].first==persona){
                    cuentas[i].second-=cantidad_por_persona*numero_de_regalos;
                }
            }

            for(int i=0;i<numero_de_regalos;i++){
                string receptor;
                cin>> receptor;
                for(int k=0;k<n_personas;k++){
                    if(cuentas[k].first==receptor){
                        cuentas[k].second+=cantidad_por_persona;
                    }
                }
            }
        }
        if (contralador++ > 1)
            cout << endl;

        if(n_personas!=0){
            for(auto x:cuentas){
                cout<<x.first<<" "<<x.second<<endl;
            }
        }
    }
    return 0;
}

