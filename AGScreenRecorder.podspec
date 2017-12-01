#
# Be sure to run `pod lib lint AGScreenRecorder.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'AGScreenRecorder'
  s.version          = '0.0.4'
  s.summary          = 'A short description of AGScreenRecorder.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/linguanjie@gmail.com/AGScreenRecorder'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'linguanjie@gmail.com' => 'linguanjie@gmail.com' }
  s.source           = { :git => 'https://github.com/linguanjie@gmail.com/AGScreenRecorder.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  # s.user_target_xcconfig = { 'Enable Bitcode' => 'NO' }
  # s.pod_target_xcconfig = { 'Enable Bitcode' => 'NO' }

  s.source_files = 'AGScreenRecorder/Classes/**/*'
  s.public_header_files = 'AGScreenRecorder/*.h'
  # s.ios.vendored_frameworks = 'AGScreenRecorder/Frameworks/*.framework'
# s.resources = 'pod-library/images.xcassets/**/*.png'

  s.resources = 'AGScreenRecorder/Assets/**/*.png','AGScreenRecorder/Assets/**/*.pdf'
  


  s.libraries = 'c++'
  s.frameworks = 'UIKit', 'AVFoundation', 'AudioToolbox', 'CoreVideo','MobileCoreServices','ReplayKit'
  # s.weak_framework = 'ReplayKit'
  s.dependency 'itmSDK'
end
