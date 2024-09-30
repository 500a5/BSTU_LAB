package com.ilya.investments.news;


import com.ilya.investments.repo.NewsRepositity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping("/api/news")

public class NewsController {
    @Autowired
    private NewsRepositity newsRepositiry;

    @GetMapping("/list")
    public List<News> list()
    {
        return newsRepositiry.findAll();
    }

    @GetMapping("/getnewsid")
    public Optional<News> stage(@RequestParam(defaultValue = "0") int id)
    {
        return newsRepositiry.findById(id);
    }


    @GetMapping("/delnewsid")
    public boolean del(@RequestParam(defaultValue = "0") int id) {
        newsRepositiry.deleteById(id);
        return true;
    }

    @GetMapping("/editnewsid")
    public boolean edit(@RequestParam(defaultValue = "0") int id, @RequestParam String name,
                        @RequestParam String text,
                        @RequestParam String img,
                        @RequestParam String date ) {
        News news = newsRepositiry.getById(id);
        news.setName(name);
        news.setText(text);
        news.setImg(img);
        news.setDate(date);
        newsRepositiry.save(news);
        return true;
    }

    @PostMapping("/addnews")
    private Boolean addNews(@RequestParam String name,
                             @RequestParam String text,
                            @RequestParam String img,
                            @RequestParam String date)
    {
        News news = new News(name,text,img,date);
       newsRepositiry.save(news);
        return true;
    }


}
