//
//  ViewController.swift
//  Test
//
//  Created by Rencheng Tan on 9/1/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate, HomeModelProtocal  {
    
    //Properties
    
    var feedItems: NSArray = NSArray()
    var selectedData : DataModel = DataModel()
    @IBOutlet weak var listTableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //set delegates and initialize homeModel
        
        self.listTableView.delegate = self
        self.listTableView.dataSource = self
        
        let homeModel = HomeModel()
        homeModel.delegate = self
        homeModel.downloadItems()
        
    }
    
    func itemsDownloaded(items: NSArray) {
        
        feedItems = items
        self.listTableView.reloadData()
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // Return the number of feed items
        return feedItems.count
        
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        // Retrieve cell
        let cellIdentifier: String = "BasicCell"
        let myCell: UITableViewCell = tableView.dequeueReusableCellWithIdentifier(cellIdentifier)!
        // Get the location to be shown
        let item: DataModel = feedItems[indexPath.row] as! DataModel
        // Get references to labels of cell
        let temp = String(item.label)
        myCell.textLabel!.text = temp
        
        return myCell
    }
    
}