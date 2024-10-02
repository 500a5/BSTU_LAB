package com.ilya.investments.user;

import com.ilya.investments.news.News;
import com.ilya.investments.repo.UserRepositiry;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.MediaType;
import java.util.ArrayList;
import java.util.List;




@RestController
@RequestMapping("/api/user")
public class UserController {
    @Autowired
    UserRepositiry userRepositiry;

    @GetMapping("/list")
    public List<User> list()
    {
        return userRepositiry.findAll();
    }


    @GetMapping("/{id}")
    public User user(@PathVariable int id)
    {
        return userRepositiry.findById(id).orElse(null);
    }


        @GetMapping(value = "/login")
        private ResponseEntity<String> login(@RequestParam String name,
                                             @RequestParam String password) {
            User user = userRepositiry.findByName(name);
            if (user != null)
            {
                if (!password.equals(user.getPassword()))
                {
                    return new ResponseEntity<>("Invalid password", HttpStatus.BAD_REQUEST);
                }
            }
            else
            {
                return new ResponseEntity<>("User doesn't exists", HttpStatus.BAD_REQUEST);
            }

            return new ResponseEntity<>("Success", HttpStatus.OK);
        }


    @PostMapping(value = "/register", consumes = { MediaType.APPLICATION_FORM_URLENCODED_VALUE })
    public ResponseEntity<String> register(User user) {

        User findedUser = userRepositiry.findByName(user.getName());
        if (findedUser != null) {
            return new ResponseEntity<>("User already contains", HttpStatus.BAD_REQUEST);
        } else {

            userRepositiry.saveAndFlush(user);
        }

        return new ResponseEntity<>("Success", HttpStatus.CREATED);

    }
}
