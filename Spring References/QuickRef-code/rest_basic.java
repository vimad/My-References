package com.vinod.todo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.hateoas.Resource;
import org.springframework.hateoas.mvc.ControllerLinkBuilder;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import java.net.URI;
import java.util.List;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class TodoController {

    @Autowired
    TodoRepository todoRepository;


    //get mapping all
    @GetMapping("/todos/{username}")
    public List<Todo> getTodosForUser(@PathVariable String username){
        List<Todo> todos = todoRepository.findByUsername(username);
        return todos;
    }


    //get mapping by id
    @GetMapping("/todos/{username}/{id}")
    public Resource<Todo> getTodoById(@PathVariable String username, @PathVariable Long id){
        Todo todo = todoRepository.findById(id).get();

        Resource<Todo> resource = new Resource<>(todo);

        ControllerLinkBuilder link = ControllerLinkBuilder
                .linkTo(ControllerLinkBuilder.methodOn(this.getClass()).getTodosForUser(username));

        resource.add(link.withRel("all-users"));
        return resource;
    }


    //post mapping
    @PostMapping("/todos/add/todo")
    public ResponseEntity<Void> addTodo(@RequestBody Todo todo){

        todo.setusername("vinod");
        System.out.println(todo);
        Todo savedTodo = todoRepository.save(todo);

        URI uri = ServletUriComponentsBuilder.fromCurrentRequest().path("/{id}").buildAndExpand(savedTodo.getId()).toUri();

        return ResponseEntity.created(uri).build();
    }


    //delete mapping
    @DeleteMapping("/todos/delete/{id}")
    public ResponseEntity<Void> deleteTodo(@PathVariable Long id){
        Todo todo = todoRepository.findById(id).get();
        todoRepository.deleteById(id);

        if(todo != null){
            return ResponseEntity.noContent().build();
        }
        return ResponseEntity.notFound().build();
    }


    //put mapping
    @PutMapping("/todos/update/{id}")
    public ResponseEntity<Todo> updateTodo(@PathVariable Long id, @RequestBody Todo todo){
        Todo updatedTodo = todoRepository.save(todo);

        return new ResponseEntity(updatedTodo, HttpStatus.OK);
    }
}
