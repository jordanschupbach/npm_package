// Simple module

import * as addon from './build/Release/addon';

const helloWorld = () => {
  console.log('Hello World');
}

const hello = (world) => { 
  return `Hello ${world}`;
}

export { addon, hello, helloWorld };
