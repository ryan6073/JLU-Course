package model;

public class Admin {
    private String id;
    private String pass;

    public Admin(String id, String pass) {
        this.id = id;
        this.pass = pass;
    }

    public String getId() {
        return this.id;
    }

    public String getPass() {
        return this.pass;
    }
}
