package com.ilya.investments.repo;

import com.ilya.investments.news.News;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface NewsRepositity extends JpaRepository<News, Integer> {

}
