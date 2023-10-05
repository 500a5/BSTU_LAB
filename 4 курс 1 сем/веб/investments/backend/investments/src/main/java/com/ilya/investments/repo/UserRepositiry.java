package com.ilya.investments.repo;

import com.ilya.investments.user.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRepositiry extends JpaRepository<User, Integer> {

    User findByName(String name);
}
