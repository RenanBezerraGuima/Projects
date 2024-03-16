public class MyFirstClass {
    public class Caixa {
        int qtd = 0;
        int tamanho = 0;

        public void aumentaQuantidade() {
            qtd = qtd++;
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello, World!!!");
        Caixa c1 = Caixa();

        System.out.println("Quantidade de caixas " + c1.qtd);
        c1.aumentaQuantidade();
        System.out.println("Quantidade de caixas " + c1.qtd);

    }
}
