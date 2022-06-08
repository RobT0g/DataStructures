/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.Class07_06;

import java.util.Set;

/**
 *
 * @author Aluno
 */
public class Lista {
    private Celula ini;
    private Celula fim;
    private int tam;
    
    public Lista(){
        this.ini = this.fim = null;
        this.tam = 0;
    }
    
    public void insert(Object elem){
       this.ini = new Celula(elem, this.ini);
       this.tam++;
       if(this.tam == 1)
           this.fim = this.ini;
    }
    
    public void push(Object elem){
        if(this.tam == 0){
            this.insert(elem);
        } else {
            Celula nova = new Celula(elem);
            this.fim.setProx(nova);
            this.fim = nova;
            this.tam++;
        }
    }
    
    public void insertAt(Object elem, int pos){
        if(this.tam == 0 && pos == 1){
            this.insert(elem);
        } else if(pos == this.tam+1){
            this.push(elem);
        } else{
        Celula cel = this.getCelAt(pos-1);
            if(cel != null){
                Celula nova = new Celula(elem, cel.getProx());
                cel.setProx(nova);
                this.tam++;
            }
        }
    }
    
    private Celula getCelAt(int pos){
        return this.iterate(pos, false);
    }

    private Celula iterate(int pos, boolean print){
        if(!this.occupied(pos) || this.tam == 0){
            return null;
        }
        Celula cur = this.ini;
        if(print) System.out.println(cur.getElem());
        for(int i = 1; i < pos; i++){
            cur = cur.getProx();
            if(cur == null) break;
            if(print) System.out.println(cur.getElem());
        }
        return cur;
    }
    
    public void printAll(){
        this.iterate(this.tam, true);
    }

    @Override
    public String toString(){
        if(this.tam == 0)
            return "[]";
        Celula cur = this.ini;
        String txt = "[" + cur.getElem();
        for(int i = 1; i < this.tam; i++){
            cur = cur.getProx();
            txt += ", " + cur.getElem();
        }
        return txt + "]";
    }
    
    private boolean occupied(int pos){
        return pos > 0 && pos <= this.tam;
    }

    public void removeFirst(){
        if(this.tam == 1)
            this.fim = null;
        else if(this.tam > 1){
            this.ini = this.ini.getProx();
            this.tam--;
        }
    }
    
    public void removeLast(){
        if(this.tam <= 1){
            this.removeFirst();
        } else {
            Celula ant = this.getCelAt(this.tam-1);
            ant.setProx(null);
            this.tam--;
        }
    }

    public void removeAt(int pos){
        if(pos == 1){
            this.removeFirst();
        } else if(pos == this.tam){
            this.removeLast();
        } else {
            Celula ant = this.getCelAt(pos-1);
            if(ant != null){
                ant.setProx(ant.getProx().getProx());
                this.tam--;
            }
        }
    }
    
    public boolean includes(Object elem){
        Celula cur = this.ini;
        for(int i = 0; i <= this.tam; i++){
            if(cur.getElem() == elem) return true;
            cur = cur.getProx();
        }
        return false;
    }
}
