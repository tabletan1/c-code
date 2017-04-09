//
//  ViewController.swift
//  HelloWord
//
//  Created by Rencheng Tan on 8/26/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    @IBAction func showmessage()
    {
        let alertController = UIAlertController(title: "welcome to my first App", message: "Hello World",
                                                preferredStyle: UIAlertControllerStyle.Alert)
        alertController.addAction(UIAlertAction(title:"ok", style: UIAlertActionStyle.Default, handler: nil))
        self.presentViewController(alertController, animated: true, completion: nil)
    }

}

