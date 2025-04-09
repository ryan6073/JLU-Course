package edu.jlu.spmvcdemo.controller;

import edu.jlu.spmvcdemo.pojo.Account;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("hc")
public class HelloController {

    @RequestMapping("hl")
    public String hello(Account account){
        System.out.println(account.getPwd());
        return "Hello,"+account.getAcc();
    }

    @RequestMapping("f1")
    public Account f1(Account account){
        return account;
    }

    @RequestMapping("f2")
    public void f2(){

    }
}
