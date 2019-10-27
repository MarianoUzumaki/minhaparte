#include "veiculo.h"
#include <vector>
                          //1-PF 2-PJ
struct propriedade {int fisoujur; std::string nomeoucnpj;};

class Concessionaria {
    private:
        propriedade dono;

        string nome;
        long long int cnpj;
        int qtd_estoque;
        std::vector<Carro> carros;
        std::vector<Moto> motos;
        std::vector<Caminhao> caminhoes;
    public:
        propriedade getPropriedade();

        void listarElem();

        Concessionaria(string n, long long int c, int b, string name);
        ~Concessionaria();
        string getNome();
        long long int getCNPJ();
        void novoCarro(Carro c);
        void novoMoto(Moto m);
        void novoCaminhao(Caminhao c);

        void buscaChassi(std::string u);

        std::vector<Carro> getCarros();
        std::vector<Moto> getMotos();
        std::vector<Caminhao> getCaminhoes();
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const c);
};

propriedade Concessionaria::getPropriedade(){
  return dono;
}

void Concessionaria::listarElem(){

  std::cout<< "Proprietário da concessionaria[1-PF  2-PJ]: " << nome << " " << dono.fisoujur << " " << dono.nomeoucnpj<<std::endl;
  std::cout<< "Total de carros: "<< carros.size()<<std::endl;
  std::cout<< "Total de motos: "<< motos.size()<<std::endl;
  std::cout<< "Total de caminhoes: "<< caminhoes.size()<<std::endl;
  std::cout<< "Total de veiculos: "<< carros.size()+motos.size()+caminhoes.size()<<std::endl;
      float valortotal =0.0;
              for (auto it = std::begin(carros); it!=std::end(carros); ++it)
                  {valortotal+= (*it).getPreco();};
              for (auto it = std::begin(motos); it!=std::end(motos); ++it)
                  {valortotal+= (*it).getPreco();};
              for (auto it = std::begin(caminhoes); it!=std::end(caminhoes); ++it)
                  {valortotal+= (*it).getPreco();};
  std::cout<< "Valor total dos veículos: " << "R$ " << valortotal << std::endl;
}

void Concessionaria::buscaChassi(std::string u){
    bool aux = false;
    std::string teste;
          //carros
      for(unsigned i=0;i<carros.size();i++)
      {teste = carros[i].getChassi();
        if (teste.compare(u) !=0)
          {aux=false;continue;}
        else
        {std::cout<<"Chassi "<< u <<" encontrado na concessionaria "<< nome<<std::endl;
        aux=true;
        std::cout<<"Carro:\n"<<"Marca: "<<carros[i].getMarca()<<"\n"<<
        "Preco: "<<carros[i].getPreco()<<"\n"<<
        "Chassi: "<<carros[i].getChassi()<<"\n"<<
        "Data: "<<carros[i].getData()<<"\n"<<
        "Tipo: "<<carros[i].getTipo()<<std::endl;
        break;};
      };

      if(aux) {return;}; //se já achou o chassi sai da função
          //motos
      for(unsigned i=0;i<motos.size();i++)
      {teste = motos[i].getChassi();
        if (teste.compare(u) !=0)
          {aux=false;continue;}
        else {std::cout<<"Chassi "<< u <<" encontrado na concessionaria "<< nome<<std::endl;
        aux=true;
        std::cout<<"Moto:\n"<<"Marca: "<<motos[i].getMarca()<<"\n"<<
        "Preco: "<<motos[i].getPreco()<<"\n"<<
        "Chassi: "<<motos[i].getChassi()<<"\n"<<
        "Data: "<<motos[i].getData()<<"\n"<<
        "Tipo: "<<motos[i].getTipo()<<std::endl;
        break;};
      };

        if(aux) {return;}; //se já achou o chassi sai da função
            //caminhões
            for(unsigned i=0;i<caminhoes.size();i++)
            {teste = caminhoes[i].getChassi();
              if (teste.compare(u) !=0)
                {aux=false;continue;}
              else {std::cout<<"Chassi "<< u <<" encontrado na concessionaria "<< nome<<std::endl;
              aux=true;
              std::cout<<"Caminhao:\n"<<"Marca: "<<caminhoes[i].getMarca()<<"\n"<<
              "Preco: "<<caminhoes[i].getPreco()<<"\n"<<
              "Chassi: "<<caminhoes[i].getChassi()<<"\n"<<
              "Data: "<<caminhoes[i].getData()<<"\n"<<
              "Tipo: "<<caminhoes[i].getTipo()<<std::endl;
              break;};
            };
    if(!aux) {std::cout<<"Chassi "<< u <<" não encontrado na concessionaria "<< nome<<std::endl;};
}

//Construtor da classe Concessionaria
Concessionaria::Concessionaria(string n, long long int c,int b, string name) {

      dono.fisoujur=b;
      dono.nomeoucnpj=name;
    nome = n;
    cnpj = c;
    qtd_estoque = 0;
}

//Destrutor da classe Concessionaria
Concessionaria::~Concessionaria() {

}

//Getter do atributo nome
string Concessionaria::getNome() {
    return nome;
}

//Getter do atributo cnpj
long long int Concessionaria::getCNPJ() {
    return cnpj;
}

//Funcao para adicionar novo carro
void Concessionaria::novoCarro(Carro c) {
    carros.push_back(c);
    qtd_estoque++;
}

//Funcao para adicionar nova moto
void Concessionaria::novoMoto(Moto m) {
    motos.push_back(m);
    qtd_estoque++;
}

//Funcao para adicionar novo caminhao
void Concessionaria::novoCaminhao(Caminhao c) {
    caminhoes.push_back(c);
    qtd_estoque++;
}

//Funcao que retorna o vetor de carros
std::vector<Carro> Concessionaria::getCarros() {
    return carros;
}

//Funcao que retorna o vetor de motos
std::vector<Moto> Concessionaria::getMotos() {
    return motos;
}

//Funcao que retorna o vetor de caminhoes
std::vector<Caminhao> Concessionaria::getCaminhoes() {
    return caminhoes;
}

//Sobrecarga do operador << na classe Concessionaria
std::ostream& operator<< (std::ostream &o, Concessionaria const c) {
    o << "Nome: " << c.nome << std::endl;
    o << "CNPJ: " << c.cnpj << std::endl;
    o << "Quantidade no estoque: " << c.qtd_estoque<< std::endl;
    o << "Dono(1-PF .. 2-PJ): " << c.dono.fisoujur << " - " << c.dono.nomeoucnpj<<std::endl;
    return o;
}
