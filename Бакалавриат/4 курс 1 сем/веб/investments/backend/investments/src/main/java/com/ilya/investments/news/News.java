package com.ilya.investments.news;

import javax.persistence.*;

@Entity
@Table(name = "news")
public class News {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    private  String name;
    private  String text;
    private  String img;
    private  String date;

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getText() {
        return text;
    }

    public String getImg() {
        return img;
    }

    public String getDate() {
        return date;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setImg(String img) {
        this.img = img;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public News(){}
    public News(String name, String text, String img, String date) {
        this.name = name;
        this.text = text;
        this.img = img;
        this.date = date;
    }
    public News(int id, String name, String text, String img, String date)
    {
        this(name,  text, img, date);

        this.id = id;
    }
}
