//
//  PlaySoundsViewController.swift
//  hello world
//
//  Created by Rencheng Tan on 8/31/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

import UIKit
import AVFoundation

class PlaySoundsViewController: UIViewController {
    
    @IBOutlet weak var SnailButton: UIButton!
    @IBOutlet weak var RabbitButton: UIButton!
    @IBOutlet weak var stopButton: UIButton!
    
    var recordedAudioURL: NSURL!
    var audioFile: AVAudioFile!
    var audioEngine: AVAudioEngine!
    var audioPlayerNode: AVAudioPlayerNode!
    var stopTimer: NSTimer!
    
    enum ButtonType: Int {case Slow = 0, Fast}
    
    @IBAction func playSoundForButton(sender: UIButton)
    {
        print("play Sound Button Pressed")
        switch(ButtonType(rawValue: sender.tag)!){
            case .Slow:
                playSound(rate:0.5)
            case .Fast:
                playSound(rate:1.5)
        }
        
        configureUI(.Playing)
    }
    
    @IBAction func stopSoundForButton(sender: AnyObject)
    {
        print("stop Sound Button Pressed")
        stopAudio()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print("PlaySoundsViewController loaded")
        setupAudio()

        // Do any additional setup after loading the view.
    }
    
    override func viewWillAppear(animated: Bool) {
        configureUI(.NotPlaying)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
