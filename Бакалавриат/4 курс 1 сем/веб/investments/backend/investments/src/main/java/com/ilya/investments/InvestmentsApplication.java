package com.ilya.investments;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@RestController
public class InvestmentsApplication {

	public static void main(String[] args) {
		SpringApplication.run(InvestmentsApplication.class, args);
	}


}
