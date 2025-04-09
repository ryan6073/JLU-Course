package entity;

public class User {
    private String id;
    private String salt;
    private String pass;
    private boolean freeze;
    private String name;
    private String email;
    private String sex;
    private String intro;

    public User() {
    }

    public User(String id, String salt, String pass, boolean freeze, String name, String email, String sex, String intro) {
        this(id, salt, pass, freeze, name, email);
        this.sex = sex;
        this.intro = intro;
    }

    public User(String id, String salt, String pass, boolean freeze, String name, String email) {
        this.id = id;
        this.salt = salt;
        this.pass = pass;
        this.freeze = freeze;
        this.name = name;
        this.email = email;
    }

    public String getSalt() {
        return this.salt;
    }

    public void setSalt(String salt) {
        this.salt = salt;
    }

    public String getPass() {
        return this.pass;
    }

    public void setPass(String pass) {
        this.pass = pass;
    }

    public boolean isFreeze() {
        return this.freeze;
    }

    public void setFreeze(boolean freeze) {
        this.freeze = freeze;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return this.sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getIntro() {
        return this.intro;
    }

    public void setIntro(String intro) {
        this.intro = intro;
    }

    public String getId() {
        return this.id;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String toString() {
        return "[id=" + this.id + ", salt=" + this.salt + ", pass=" + this.pass + ", freeze=" + this.freeze + ", name=" + this.name + ", email=" + this.email + ", sex=" + this.sex + ", intro=" + this.intro + "]";
    }
}
