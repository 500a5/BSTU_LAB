package com.ilya.investments.user;
import com.sun.istack.NotNull;
import javax.persistence.*;

@Entity
@Table(name = "user")

public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private  String name;
    private  String password;


    public User(String name, String password) {
        this.name = name;
        this.password = password;

    }
    public User(int id, String name, String password)
    {
        this(name,  password);

        this.id = id;
    }

    public User() {

    }

    public int getId()
    {
        return id;
    }

    public String getName()
    {
        return name;
    }


    public String getPassword()
    {
        return password;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
