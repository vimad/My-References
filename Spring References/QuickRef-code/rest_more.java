//*****************Resource Acembler****************************
import static org.springframework.hateoas.mvc.ControllerLinkBuilder.*;

import org.springframework.hateoas.Resource;
import org.springframework.hateoas.ResourceAssembler;
import org.springframework.stereotype.Component;

@Component
class EmployeeResourceAssembler implements ResourceAssembler<Employee, Resource<Employee>> {

	@Override
	public Resource<Employee> toResource(Employee employee) {

		return new Resource<>(employee,
			linkTo(methodOn(EmployeeController.class).one(employee.getId())).withSelfRel(),
			linkTo(methodOn(EmployeeController.class).all()).withRel("employees"));
	}
}


//************************Methods**********************************
@GetMapping("/employees/{id}")
Resource<Employee> one(@PathVariable Long id) {

	Employee employee = repository.findById(id)
		.orElseThrow(() -> new EmployeeNotFoundException(id));

	return assembler.toResource(employee);
}


@GetMapping("/employees")
Resources<Resource<Employee>> all() {

	List<Resource<Employee>> employees = repository.findAll().stream()
		.map(assembler::toResource)
		.collect(Collectors.toList());

	return new Resources<>(employees,
		linkTo(methodOn(EmployeeController.class).all()).withSelfRel());
}


@PostMapping("/employees")
ResponseEntity<?> newEmployee(@RequestBody Employee newEmployee) throws URISyntaxException {

	Resource<Employee> resource = assembler.toResource(repository.save(newEmployee));

	return ResponseEntity
		.created(new URI(resource.getId().expand().getHref()))
		.body(resource);
}


@PutMapping("/employees/{id}")
ResponseEntity<?> replaceEmployee(@RequestBody Employee newEmployee, @PathVariable Long id) throws URISyntaxException {

	Employee updatedEmployee = repository.findById(id)
		.map(employee -> {
			employee.setName(newEmployee.getName());
			employee.setRole(newEmployee.getRole());
			return repository.save(employee);
		})
		.orElseGet(() -> {
			newEmployee.setId(id);
			return repository.save(newEmployee);
		});

	Resource<Employee> resource = assembler.toResource(updatedEmployee);

	return ResponseEntity
		.created(new URI(resource.getId().expand().getHref()))
		.body(resource);
}


@DeleteMapping("/employees/{id}")
ResponseEntity<?> deleteEmployee(@PathVariable Long id) {

	repository.deleteById(id);

	return ResponseEntity.noContent().build();
}



@Component
class OrderResourceAssembler implements ResourceAssembler<Order, Resource<Order>> {

	@Override
	public Resource<Order> toResource(Order order) {

		// Unconditional links to single-item resource and aggregate root

		Resource<Order> orderResource = new Resource<>(order,
			linkTo(methodOn(OrderController.class).one(order.getId())).withSelfRel(),
			linkTo(methodOn(OrderController.class).all()).withRel("orders")
		);

		// Conditional links based on state of the order

		if (order.getStatus() == Status.IN_PROGRESS) {
			orderResource.add(
				linkTo(methodOn(OrderController.class)
					.cancel(order.getId())).withRel("cancel"));
			orderResource.add(
				linkTo(methodOn(OrderController.class)
					.complete(order.getId())).withRel("complete"));
		}

		return orderResource;
	}
}
///**************************Special Validation **************************
@Component
class OrderResourceAssembler implements ResourceAssembler<Order, Resource<Order>> {

	@Override
	public Resource<Order> toResource(Order order) {

		// Unconditional links to single-item resource and aggregate root

		Resource<Order> orderResource = new Resource<>(order,
			linkTo(methodOn(OrderController.class).one(order.getId())).withSelfRel(),
			linkTo(methodOn(OrderController.class).all()).withRel("orders")
		);

		// Conditional links based on state of the order

		if (order.getStatus() == Status.IN_PROGRESS) {
			orderResource.add(
				linkTo(methodOn(OrderController.class)
					.cancel(order.getId())).withRel("cancel"));
			orderResource.add(
				linkTo(methodOn(OrderController.class)
					.complete(order.getId())).withRel("complete"));
		}

		return orderResource;
	}
}


@DeleteMapping("/orders/{id}/cancel")
ResponseEntity<ResourceSupport> cancel(@PathVariable Long id) {

	Order order = orderRepository.findById(id).orElseThrow(() -> new OrderNotFoundException(id));

	if (order.getStatus() == Status.IN_PROGRESS) {
		order.setStatus(Status.CANCELLED);
		return ResponseEntity.ok(assembler.toResource(orderRepository.save(order)));
	}

	return ResponseEntity
		.status(HttpStatus.METHOD_NOT_ALLOWED)
		.body(new VndErrors.VndError("Method not allowed", "You can't cancel an order that is in the " + order.getStatus() + " status"));
}


@PutMapping("/orders/{id}/complete")
ResponseEntity<ResourceSupport> complete(@PathVariable Long id) {

		Order order = orderRepository.findById(id).orElseThrow(() -> new OrderNotFoundException(id));

		if (order.getStatus() == Status.IN_PROGRESS) {
			order.setStatus(Status.COMPLETED);
			return ResponseEntity.ok(assembler.toResource(orderRepository.save(order)));
		}

		return ResponseEntity
			.status(HttpStatus.METHOD_NOT_ALLOWED)
			.body(new VndErrors.VndError("Method not allowed", "You can't complete an order that is in the " + order.getStatus() + " status"));
}


