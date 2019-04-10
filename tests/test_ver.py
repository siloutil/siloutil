import siloutil
import unittest

class TestStringMethods(unittest.TestCase):

    def test_ver(self):
        self.assertEqual(siloutil.greet(), '4.10.2')

if __name__ == '__main__':
    unittest.main()
