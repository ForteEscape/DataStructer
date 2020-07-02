package Week4;

import java.util.Scanner;

public class PolynomialExpress{
    static Polynomial[] polys = new Polynomial[100];
    static int number = 0;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.print("$");
            String command = sc.next();

            if(command.equals("exit")){
                break;
            }
            else if(command.equals("create")){
                char name = sc.next().charAt(0);

                createPolynomial(name);
            }
            else if(command.equals("calc")){
                char name = sc.next().charAt(0);
                int idx = find(name);

                if(idx == -1){
                    System.out.println("No Such Polynomial exsist");
                }
                else{
                    int number = sc.nextInt();
                    int result = calcPolynomial(polys[idx], number);

                    System.out.println(result);
                }
            }
            else if(command.equals("print")){
                char name = sc.next().charAt(0);
                int idx = find(name);

                if(idx == -1){
                    System.out.println("No Such Polynomial exsist");
                }
                else{
                    printPolynomial(polys[idx]);
                }
            }
            else if(command.equals("add")){
                char name = sc.next().charAt(0);
                int idx = find(name);
                
                if(idx == -1){
                    System.out.println("No such polynomial exsist");
                }
                else{
                    int cof = sc.nextInt();
                    int exp = sc.nextInt();

                    addTerm(polys[idx], cof, exp);
                }
            }
        }

        sc.close();
    }

    static void createPolynomial(char name){
       polys[number] = new Polynomial();
       polys[number].name = name;
       polys[number].nTerms = 0;
       polys[number].terms = new Term[100];
       number++;
    }

    static int find(char name){
        for(int i = 0; i<number; i++){
            if(polys[i].name == name){
                return i;
            }
        }
        return -1;
    }

    static void addTerm(Polynomial p, int cof, int exp){
        int index = findTerm(p, exp);
        if(index != -1){
            p.terms[index].coef += cof;
        }
        else{
            int i = p.nTerms-1;
            while(i>=0 && p.terms[i].exp < exp){
                p.terms[i+1] = p.terms[i];
                i--;
            }
            p.terms[i+1] = new Term();
            p.terms[i+1].coef = cof;
            p.terms[i+1].exp = exp;
            p.nTerms++;
        }
    }

    static int findTerm(Polynomial p, int e){
        for(int i = 0; i<p.nTerms && p.terms[i].exp >= e; i++){
            if(p.terms[i].exp == e){
                return i;
            }
        }
        return -1;
    }

    static void printPolynomial(Polynomial p){
        for(int i = 0; i<p.nTerms; i++){
            printTerm(p.terms[i]);
            System.out.print("+");
        }
        System.out.println("");
    }

    static void printTerm(Term term){
        System.out.println(term.coef + "x^"+term.exp);
    }

    static int calcPolynomial(Polynomial p, int number){
        int result = 0;

        for(int i = 0; i<p.nTerms; i++){
            result += calcTerm(p.terms[i], number);
        }

        return result;
    }

    static int calcTerm(Term term, int number){
        return (int)(term.coef * Math.pow(number, term.exp));
    }
}