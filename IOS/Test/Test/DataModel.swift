//
//  DataModel.swift
//  Test
//
//  Created by Rencheng Tan on 9/1/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

import Foundation

class DataModel: NSObject
{
    var label: String?
    var Pre_20: String?
    var Pre_40: String?
    var Pre_60: String?
    var Pre_80: String?
    var Pre_100: String?
    var Pre_120: String?
    
    var Vol_20: String?
    var Vol_40: String?
    var Vol_60: String?
    var Vol_80: String?
    var Vol_100: String?
    var Vol_120: String?

    
    
    override init()
    {
        
    }
    
    init(Pre_20: String, Pre_40: String,Pre_60: String,Pre_80: String,Pre_100: String,Pre_120: String,Vol_20: String,Vol_40: String,Vol_60: String,Vol_80: String,Vol_100: String,Vol_120: String, label: String?)
    {
        self.label = label
        self.Pre_20 = Pre_20
        self.Pre_40 = Pre_40
        self.Pre_60 = Pre_60
        self.Pre_80 = Pre_80
        self.Pre_100 = Pre_100
        self.Pre_120 = Pre_120
        self.Vol_20 = Vol_20
        self.Vol_40 = Vol_40
        self.Vol_60 = Vol_60
        self.Vol_80 = Vol_80
        self.Vol_100 = Vol_100
        self.Vol_120 = Vol_120
        
        
    }
    
    override var description: String {
        let a =  "label: \(label), Pre_20: \(Pre_20), Pre_40: \(Pre_40), Pre_60: \(Pre_60), Pre_80: \(Pre_80), Pre_100: \(Pre_100), Pre_120: \(Pre_120)"
        let b =  "Vol_20: \(Vol_20), Vol_40: \(Vol_40), Vol_60: \(Vol_60), Vol_80: \(Vol_80), Vol_100: \(Vol_100), Vol_120: \(Vol_120)"
        return(a+b)
    }

}