use std::ptr;

/// Basic FIFO Queue implementation using a linked list with unsafe rust
/// pointers. Implementation supports the most common operations (push/pop)
/// as well as the various iterator types
pub struct Queue<T> {
    head: Link<T>,
    tail: *mut Node<T>, // Danger unsafe pointer
}

type Link<T> = Option<Box<Node<T>>>;

struct Node<T> {
    elem: T,
    next: Link<T>,
}

pub struct IntoIter<T>(Queue<T>);

pub struct Iter<'a, T: 'a> {
    next: Option<&'a Node<T>>,
}

pub struct IterMut<'a, T: 'a> {
    next: Option<&'a mut Node<T>>,
}

impl<T> Queue<T> {
    // Creates a new queue
    pub fn new() -> Self {
        Queue {
            head: None,
            tail: ptr::null_mut(),
        }
    }

    // Enqueues the given element at the end of the queue
    pub fn push(&mut self, elem: T) {
        let mut new_tail = Box::new(Node {
            elem: elem,
            next: None, // Last elem allways has next = None
        });

        let raw_tail: *mut _ = &mut *new_tail;

        if !self.tail.is_null() {
            // If old tail exists, update to point to the new tail
            unsafe {
                (*self.tail).next = Some(new_tail);
            }
        } else {
            // If not, update head to point to it
            self.head = Some(new_tail);
        }

        self.tail = raw_tail;
    }

    // Dequeues the first element in the queue
    pub fn pop(&mut self) -> Option<T> {
        // Grab current queue head
        self.head.take().map(|head| {
            let head = *head;
            self.head = head.next;

            // If queue now becomes empty, set tail to null aswell
            if self.head.is_none() {
                self.tail = ptr::null_mut();
            }

            head.elem
        })
    }

    // Returns a immutable reference to the first element, None if empty
    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.elem)
    }

    // Returns a mutable reference to the first element, None if empty
    pub fn peek_mut(&mut self) -> Option<&mut T> {
        self.head.as_mut().map(|node| &mut node.elem)
    }

    // Turns the queue into an iterator
    pub fn into_iter(self) -> IntoIter<T> {
        IntoIter(self)
    }

    // Return a immutable iterator for the queue
    pub fn iter(&self) -> Iter<T> {
        Iter { next: self.head.as_ref().map(|node| &**node) }
    }

    // Return a mutable iterator for the queue
    pub fn iter_mut(&mut self) -> IterMut<T> {
        IterMut { next: self.head.as_mut().map(|node| &mut **node) }
    }
}

impl<T> Drop for Queue<T> {
    fn drop(&mut self) {
        let mut cur_link = self.head.take();
        while let Some(mut boxed_node) = cur_link {
            cur_link = boxed_node.next.take();
        }
    }
}

impl<T> Iterator for IntoIter<T> {
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        self.0.pop()
    }
}

impl<'a, T> Iterator for Iter<'a, T> {
    type Item = &'a T;

    fn next(&mut self) -> Option<Self::Item> {
        self.next.map(|node| {
            self.next = node.next.as_ref().map(|node| &**node);
            &node.elem
        })
    }
}

impl<'a, T> Iterator for IterMut<'a, T> {
    type Item = &'a mut T;

    fn next(&mut self) -> Option<Self::Item> {
        self.next.take().map(|node| {
            self.next = node.next.as_mut().map(|node| &mut **node);
            &mut node.elem
        })
    }
}

mod test {
    use super::Queue;

    #[test]
    fn base_functionality() {
        let mut queue = Queue::new();

        // Check that empty behaves correctly
        assert_eq!(queue.pop(), None);

        // Populate
        queue.push(1);
        queue.push(2);
        queue.push(3);

        // Check normal 'poping'
        assert_eq!(queue.pop(), Some(1));
        assert_eq!(queue.pop(), Some(2));


        // Push some more
        queue.push(4);
        queue.push(5);

        // Check normal 'poping'
        assert_eq!(queue.pop(), Some(3));
        assert_eq!(queue.pop(), Some(4));

        // Check 'poping' empty again
        assert_eq!(queue.pop(), Some(5));
        assert_eq!(queue.pop(), None);


        // Check the exhaustion case fixed the pointer right
        queue.push(6);
        queue.push(7);

        // Check normal 'popping'
        assert_eq!(queue.pop(), Some(6));
        assert_eq!(queue.pop(), Some(7));
        assert_eq!(queue.pop(), None);
    }

    #[test]
    fn peek() {
        let mut queue = Queue::new();

        assert_eq!(queue.peek(), None);
        assert_eq!(queue.peek_mut(), None);

        queue.push(1);
        queue.push(2);
        queue.push(3);

        assert_eq!(queue.peek(), Some(&1));
        assert_eq!(queue.peek_mut(), Some(&mut 1));
    }

    #[test]
    fn into_iter() {
        let mut queue = Queue::new();

        queue.push(1);
        queue.push(2);
        queue.push(3);

        let mut iter = queue.into_iter();
        assert_eq!(iter.next(), Some(1));
        assert_eq!(iter.next(), Some(2));
        assert_eq!(iter.next(), Some(3));
        assert_eq!(iter.next(), None);
    }

    #[test]
    fn iter() {
        let mut queue = Queue::new();

        queue.push(1);
        queue.push(2);
        queue.push(3);

        let mut iter = queue.iter();
        assert_eq!(iter.next(), Some(&1));
        assert_eq!(iter.next(), Some(&2));
        assert_eq!(iter.next(), Some(&3));
        assert_eq!(iter.next(), None);
    }

    #[test]
    fn iter_mut() {
        let mut queue = Queue::new();

        queue.push(1);
        queue.push(2);
        queue.push(3);

        let mut iter = queue.iter_mut();
        assert_eq!(iter.next(), Some(&mut 1));
        assert_eq!(iter.next(), Some(&mut 2));
        assert_eq!(iter.next(), Some(&mut 3));
        assert_eq!(iter.next(), None);
    }
}
