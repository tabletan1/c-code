//
//  HomeModel.swift
//  Test
//
//  Created by Rencheng Tan on 9/1/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

import Foundation

protocol HomeModelProtocal: class {
    func itemsDownloaded(items: NSArray)
}

class HomeModel: NSObject, NSURLSessionDataDelegate {
    
    //properties
    
    weak var delegate: HomeModelProtocal!
    
    var data : NSMutableData = NSMutableData()
    
    let urlPath: String = "http://localhost/service.php" //this will be changed to the path where service.php lives
    
    
    func downloadItems() {
        
        let url: NSURL = NSURL(string: urlPath)!
        var session: NSURLSession!
        let configuration = NSURLSessionConfiguration.defaultSessionConfiguration()
        
        
        session = NSURLSession(configuration: configuration, delegate: self, delegateQueue: nil)
        
        let task = session.dataTaskWithURL(url)
        
        task.resume()
        
    }
    
    func URLSession(session: NSURLSession, dataTask: NSURLSessionDataTask, didReceiveData data: NSData) {
        self.data.appendData(data);
        
    }
    
    func URLSession(session: NSURLSession, task: NSURLSessionTask, didCompleteWithError error: NSError?) {
        if error != nil {
            print("Failed to download data")
        }else {
            print("Data downloaded")
            print(self.data)
            self.parseJSON()
            
        }
    }
    
    func parseJSON() {
        
        var jsonResult: NSMutableArray = NSMutableArray()
        
        do{
            jsonResult = try NSJSONSerialization.JSONObjectWithData(self.data, options:NSJSONReadingOptions.AllowFragments) as! NSMutableArray
            
        }
        catch let error as NSError {
            print(error)
            
        }
        
        var jsonElement: NSDictionary = NSDictionary()
        let sensorDatas: NSMutableArray = NSMutableArray()
        var i = 1
        while i < jsonResult.count
        {
            
            jsonElement = jsonResult[i] as! NSDictionary
            
            let sensorData = DataModel()
            
            //the following insures none of the JsonElement values are nil through optional binding
            if
                let label = jsonElement["label"] as? String,
                let Pre_20 = jsonElement["Pre_20"] as? String,
                let Pre_40 = jsonElement["Pre_40"] as? String,
                let Pre_60 = jsonElement["Pre_60"] as? String,
                let Pre_80 = jsonElement["Pre_80"] as? String,
                let Pre_100 = jsonElement["Pre_100"] as? String,
                let Pre_120 = jsonElement["Pre_120"] as? String,
                let Vol_20 = jsonElement["Vol_20"] as? String,
                let Vol_40 = jsonElement["Vol_40"] as? String,
                let Vol_60 = jsonElement["Vol_60"] as? String,
                let Vol_80 = jsonElement["Vol_80"] as? String,
                let Vol_100 = jsonElement["Vol_100"] as? String,
                let Vol_120 = jsonElement["Vol_120"] as? String
            
            {
                sensorData.label = label
                sensorData.Pre_20 = Pre_20
                sensorData.Pre_40 = Pre_40
                sensorData.Pre_60 = Pre_60
                sensorData.Pre_80 = Pre_80
                sensorData.Pre_100 = Pre_100
                sensorData.Pre_120 = Pre_120
                sensorData.Vol_20 = Vol_20
                sensorData.Vol_40 = Vol_40
                sensorData.Vol_60 = Vol_60
                sensorData.Vol_80 = Vol_80
                sensorData.Vol_100 = Vol_100
                sensorData.Vol_120 = Vol_120
                
            }
            print("/(sensorData)")
            sensorDatas.addObject(sensorData)
            i = i+1
            
        }
        
        dispatch_async(dispatch_get_main_queue(), { () -> Void in
            
            self.delegate.itemsDownloaded(sensorDatas)
            
        })

}


}