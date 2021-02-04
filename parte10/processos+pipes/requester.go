package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strings"
	"sync"
)

var wg sync.WaitGroup = sync.WaitGroup{}
var m sync.Mutex = sync.Mutex{}

func main() {
	filename := os.Getenv("INPUT")
	if filename == "" {
		fmt.Println("Missing input file enviroment variable")
		return
	}
	read, err := ioutil.ReadFile(filename)
	if err != nil {
		fmt.Println("Couldn't find input file: " + err.Error())
	}
	links := strings.Split(string(read), "\n")
	for _, link := range links {
		wg.Add(1)
		go requester(link)
	}
	wg.Wait()
}

func requester(link string) {
	resp, err := http.Get("http://" + link)
	if err != nil {
		log.Fatal(err)
	}
	m.Lock()
	fmt.Println(fmt.Sprintf("Request to %s - %v\n", link, resp.Status))
	m.Unlock()
	wg.Done()
}
